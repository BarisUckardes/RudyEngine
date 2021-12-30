#pragma once
#include <Rudy/Platform/OS/PlatformOSType.h>

namespace Rudy
{
	PlatformOSType RUDY_API GetCurrentPlatform()
	{
		#ifdef RUDY_OS_WINDOWS
				return PlatformOSType::Windows;
		#elif RUDY_OS_LINUX
				return PlatformOSType::Linux;
		#endif

	}
}