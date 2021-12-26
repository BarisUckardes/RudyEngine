#pragma once
#ifdef RUDY_BUILD

#define RUDY_API __declspec(dllexport)

#elif

#define RUDY_API __declspec(dllimport)

#endif // RUDY_BUILD FOR IMPORT EXPORT DLL

#if RUDY_WINDOWS

#endif // RUDY_WINDOWS FOR PLATFORM DECLARATIONS

#define FORCEINLINE __forceinline

