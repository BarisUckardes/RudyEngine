#pragma once
#include <Rudy/Platform/Implementation/OS/Windows/Log/WindowsLog.h>

#ifdef RUDY_OS_WINDOWS
#define LOG_IMPLEMENTATION(message,...) LOG_WINDOWS_IMPLEMENTATION(message,__VA_ARGS__)
#elif RUDY_OS_LINUX

#endif