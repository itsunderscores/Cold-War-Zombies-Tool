#pragma once
#include "BufferVulDirver.h"
#include "BufferBat.h"

#include "../kdmapper/exports.h"
class BypassInstaller
{
public:
	bool ClearMapperLogs();
	bool LoadVulnerableDriver();
	bool MapDriver();
private:
	// make them constexpr?
	const std::string driver_name = ("scmbusl.sys");
	const std::string loadbat_name = ("load.bat");


	bool CreateFileFromMemory(const std::string& desired_file_path, const char* address, size_t size);

};



inline bool BypassInstaller::ClearMapperLogs()
{
	
	const char* log_names[] = { ("Application"), ("Security"), ("Setup"), ("System") };

	DWORD logs_cleared = 0;
	HANDLE hLog;

	for (int i = 0; i < 4; i++) {
		hLog = OpenEventLog(NULL, log_names[i]);
		if (hLog)
			if (ClearEventLog(hLog, NULL)) {
				logs_cleared++;
				CloseEventLog(hLog);
			}
	}

	if (hLog)
	{
		CloseHandle(hLog);

		if (logs_cleared == 4)
			return true;
	}
	else
	{
		std::cerr << ("Couldn't clear mapper logs.") << std::endl;
	}
	
	return false;
}

inline bool BypassInstaller::LoadVulnerableDriver()
{
	
	std::system(("sc stop scmbusl"));
	std::system(("cls"));

	char temp_directory[MAX_PATH] = { 0 };
	const uint32_t get_temp_path_ret = GetTempPathA(sizeof(temp_directory), temp_directory);
	if (!get_temp_path_ret || get_temp_path_ret > MAX_PATH) return false;
	const std::string driver_path = std::string(temp_directory) + "\\" + driver_name;
	if (!CreateFileFromMemory(driver_path, reinterpret_cast<const char*>(scmbusl_data), sizeof(scmbusl_data))) return false;


	char temp_directory1[MAX_PATH] = { 0 };
	const uint32_t get_temp_path_ret1 = GetTempPathA(sizeof(temp_directory1), temp_directory1);
	if (!get_temp_path_ret1 || get_temp_path_ret1 > MAX_PATH) return false;
	const std::string Loadbat_path = std::string(temp_directory1) + "\\" + loadbat_name;
	if (!CreateFileFromMemory(Loadbat_path, reinterpret_cast<const char*>(Loadbat), sizeof(Loadbat))) return false;
	// loads the driver.
	std::system(Loadbat_path.c_str());
	std::system(("cls"));


	const auto removeTempdriver = std::remove(driver_path.c_str());

	if (removeTempdriver != 0)
		return false;

	const auto removeTempBatfile = std::remove(Loadbat_path.c_str());

	if (removeTempBatfile != 0)
		return false;
	
	return true;
}

inline bool BypassInstaller::CreateFileFromMemory(const std::string& desired_file_path, const char* address, size_t size) {
	
	std::ofstream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);

	if (!file_ofstream.write(address, size))
	{
		file_ofstream.close();
		return false;
	}

	file_ofstream.close();
	
	return true;
}
inline bool BypassInstaller::MapDriver() 
{
	
	kdmappermain();
	
	return true;
}
