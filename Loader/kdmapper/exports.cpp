#include "kdmapper.hpp"
#include "version.h"

#include "exports.h"
#define EXPORT extern "C" __declspec(dllexport)
//#define GAME_EXE ("EscapeFromTarkov.exe")

void DebugWait(int seconds)
{
	
	printf(("Waiting... "));
	for (int i = 1; i <= seconds; i++)
	{
		Sleep(1000);
		printf("%i ", i);
	}
	printf("\n");
	
}

__forceinline int FakeMapDriver()
{
	
	HANDLE iqvw64e_device_handle = intel_driver::Load();

	if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE)
	{
		std::cout << ("Failed To Load Vulnerable Driver") << std::endl;
		return -1;
	}

	if (!kdmapper::MapDriver(iqvw64e_device_handle))
	{
		std::cout << ("Failed To Map ") << std::endl;
		intel_driver::Unload(iqvw64e_device_handle);
		return -1;
	}

	intel_driver::Unload(iqvw64e_device_handle);
	std::cout << ("Success") << std::endl;
	DebugWait(2);
	
	return 0;
}

__forceinline int dll_MapDriver()
{
	
	//AllocConsole();
	//freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
	//freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	//ShowWindow(GetConsoleWindow(), SW_SHOW);
	int status = FakeMapDriver();

	//Sleep(3000);
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	
	return status;
}

int fakemain()
{
	

	printf(("Checking version...\n"));
	auto version = GetRealOSVersion();
	printf("Build: %lu Major: %lu Minor: %lu\n", version.dwBuildNumber, version.dwMajorVersion, version.dwMinorVersion);
	dll_MapDriver();

	return 0;

	
}

int kdmappermain() 
{
	
	fakemain();
	
	return 0;
}
