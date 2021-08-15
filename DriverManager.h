#pragma once




constexpr auto Hooked_ioctl = 0xC3506104; // original read physical memory.

// don't touch this so it can be aligned with the original one in the vulnerable driver.
typedef struct read
{
	UINT64 address;
	UINT32 something;
	UINT32 size;
} _read;

typedef struct COMST {
	ULONG64 BaseAddress;
	const char* moduleName;
	UINT64 SwitchCode;
	ULONG process_id;
	bool pidTraces_cleared;
	size_t size;
	uintptr_t address;
	void* buffer;
	bool write;
}_COMST;

class DriverManager
{
public:

	DriverManager(std::string_view DriverName);
	ULONG64 GetModuleBaseAddr(std::string_view moduleName);
	bool GetProcessID(std::string_view process_name);


	template<class T>
	bool Callhook(const T pointer_to_struct) {

		// dummy param
		UINT32 size = 0;

		_read r = { reinterpret_cast<UINT64>(pointer_to_struct), 1, size };

		return DeviceIoControl(this->driver_handle.get(), Hooked_ioctl, &r, sizeof(r), 0, size, nullptr, nullptr);
	}

	template <class T>
	T ReadMemory(uintptr_t ReadAddress) {

		_COMST readopr;
		readopr.address = ReadAddress;
		readopr.SwitchCode = 0xAA11B198;
		readopr.size = sizeof(T);
		readopr.process_id = this->process_id;
		readopr.write = false;

		this->Callhook(&readopr);

		return *reinterpret_cast<T*>(&readopr.buffer);
	}

	/*
	uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
	{
		uintptr_t addr = ptr;
		for (unsigned int i = 0; i < offsets.size(); ++i)
		{
			ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
			addr += offsets[i];
		}
		return addr;
	}
	*/

	template<typename S>
	bool WriteMemory(UINT_PTR WriteAddress, const S& value)
	{
		return WriteVirtualMemoryRaw(WriteAddress, (UINT_PTR)&value, sizeof(S));
	}
	bool WriteVirtualMemoryRaw(UINT_PTR WriteAddress, UINT_PTR SourceAddress, SIZE_T WriteSize)
	{
		_COMST writeopr;

		writeopr.address = WriteAddress;
		writeopr.buffer = reinterpret_cast<void*>(SourceAddress);
		writeopr.process_id = this->process_id;
		writeopr.size = WriteSize;
		writeopr.SwitchCode = 0xAA11B198;
		writeopr.write = true;

		this->Callhook(&writeopr);

		return true;
	}

private:

	ULONG process_id;

	struct HandleDisposer
	{
		using pointer = HANDLE;
		void operator()(HANDLE handle) const
		{
			if (handle != NULL || handle != INVALID_HANDLE_VALUE)
			{
				CloseHandle(handle);
			}
		}
	};

	std::unique_ptr<HANDLE, HandleDisposer> driver_handle;
	using unique_handle = std::unique_ptr<HANDLE, HandleDisposer>;

	bool ClearMapperTraces();
	bool ClearPidCache();
};

inline DriverManager::DriverManager(std::string_view DriverName) {

	// get handle to the vulnerable driver.
	auto hfile = std::unique_ptr<HANDLE, HandleDisposer>(CreateFileA(DriverName.data(), GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0));

	this->driver_handle = std::move(hfile); // moves the object ownership to our own.

	if (this->driver_handle.get() == nullptr || this->driver_handle.get() == INVALID_HANDLE_VALUE)
	{
		std::cerr << "[-] Couldn't obtain a handle to the driver." << " " << "0x" << std::hex << this->driver_handle.get() << std::endl;
		throw 0; // temporary thing. which is gay. to stop from executing any further more.
	}

	// clear mapper traces needs to be done after installing the bypass.
	if (!this->ClearMapperTraces())
	{
		std::cerr << "[-] Some operation didn't complete successfully. Aborting in 5 seconds." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		system("exit");
	}
}

inline ULONG64 DriverManager::GetModuleBaseAddr(std::string_view moduleName) {

	_COMST getbase;
	getbase.moduleName = moduleName.data();
	getbase.SwitchCode = 0xCC11B198;
	getbase.process_id = this->process_id;

	this->Callhook(&getbase);
	ULONG64 base = NULL;
	base = getbase.BaseAddress;

	return base;
}

inline bool DriverManager::ClearPidCache() {

	_COMST clearpid;
	clearpid.SwitchCode = 0xBB11B198;

	this->Callhook(&clearpid);

	return clearpid.pidTraces_cleared;
}

inline bool DriverManager::GetProcessID(std::string_view process_name) {
	PROCESSENTRY32 processentry;
	const unique_handle snapshot_handle(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));

	if (snapshot_handle.get() == INVALID_HANDLE_VALUE)
		return 0;

	processentry.dwSize = sizeof(MODULEENTRY32);

	while (Process32Next(snapshot_handle.get(), &processentry) == TRUE) {
		if (process_name.compare(processentry.szExeFile) == 0)
		{
			this->process_id = processentry.th32ProcessID;
			//return processentry.th32ProcessID;
			return true;
		}

	}
	return false;
}

inline bool DriverManager::ClearMapperTraces() {

	if (this->ClearPidCache())
	{
		this->ClearMapperTraces(); // call our function again. recursion lol.
	}
	else
	{
		return true; // traces cleared.
	}

	return false;
}