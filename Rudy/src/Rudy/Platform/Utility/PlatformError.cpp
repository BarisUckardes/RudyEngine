#include "PlatformError.h"
#include <Rudy/Platform/OS/PlatformOSDetection.h>
#include <Rudy/Platform/OS/Windows/Utility/WindowsError.h>
namespace Rudy
{
	String PlatformError::GetLastOSError()
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsError::GetLastOSError();
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
	}
}