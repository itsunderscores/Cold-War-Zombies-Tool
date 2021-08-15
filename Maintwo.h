#pragma once

#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <stdint.h>
#include <tchar.h>
#include <time.h>
#include <memory>
#include <string_view>
#include <filesystem>
#include <fstream>
#include <thread>         
#include <chrono>      
#include <random>
#include <string>
#include <vector>
#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include"DriverManager.h"
#include "toggles.h"
#include <basetsd.h>
#include <string>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"
#include "overlay.h"
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <ostream>
#include <regex>
#include <thread>
#include <random>
#include <time.h>
#include <memory>

using namespace std;

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);

#define playerCordsOffset { 0xDE8 }
#define camoOffset  { 0x1205A4 }
#define camoOffset2 { 0x13EB5A }
#define camoOffset3 { 0x15D110 }
#define camoOffset4 { 0x17B6C6 }
#define Index { 0x1E5B6 }