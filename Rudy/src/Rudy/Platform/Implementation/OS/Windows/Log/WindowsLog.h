#pragma once
#ifdef RUDY_OS_WINDOWS
#include <stdio.h>
#define LOG_WINDOWS_IMPLEMENTATION(message,...) printf(message,__VA_ARGS__); printf("\n");
#endif