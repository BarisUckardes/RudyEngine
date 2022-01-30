#pragma once
#ifdef RUDY_BUILD
#define RUDY_API __declspec(dllexport)
#else
#define RUDY_API __declspec(dllimport)
#endif // RUDY_BUILD FOR IMPORT EXPORT DLL

#define RUDY_EXPORT __declspec(dllexport)

#define FORCEINLINE __forceinline

