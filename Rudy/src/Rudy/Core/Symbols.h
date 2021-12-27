#pragma once
#ifdef RUDY_BUILD
#define RUDY_API __declspec(dllexport)
#else
#define RUDY_API __declspec(dllimport)
#endif // RUDY_BUILD FOR IMPORT EXPORT DLL

#define RUDY_EXPORT __declspec(dllexport)

#if RUDY_WINDOWS
#define RUDY_DEBUG_BREAK __debugbreak();
#endif // RUDY_WINDOWS FOR PLATFORM DECLARATIONS
#define FORCEINLINE __forceinline

