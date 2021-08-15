#include <iostream>
#include <filesystem>
#include <atlstr.h>
#include <winternl.h>
#include <assert.h>
#include <windows.h>
#include <stdint.h>
#include <vector>
#include <thread>
#include <tchar.h>
#include <string>
#include <time.h>
#include <TlHelp32.h>
#include <random>
#include <fstream>
#include "BypassInstaller/BypassInstaller.h"
using namespace std;
bool enabledebug;
bool IsD3stiny;
std::string BrandName;
std::string chars{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?" };
std::random_device rd;
std::mt19937 generator(rd());
std::string rand_str(size_t length)
{
   
    const size_t char_size = chars.size();
    std::uniform_int_distribution<> random_int(0, char_size - 1);
    std::string output;
    for (size_t i = 0; i < length; ++i)
        output.push_back(chars[random_int(generator)]);
    
    return output;
}
int DoBypassInstaller()
{
   
    std::unique_ptr<BypassInstaller> bypass_installer = std::make_unique<BypassInstaller>();

    if (!bypass_installer->LoadVulnerableDriver())
        return -1;

    if (!bypass_installer->MapDriver())
        return -1;

    if (!bypass_installer->ClearMapperLogs())
        return -1;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::system("exit");
    
}
void menuStart()
{
    exit(0);
}