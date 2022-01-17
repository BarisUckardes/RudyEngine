#include "PlatformMutex.h"
#include <Rudy/Platform/OS/PlatformOSDetection.h>
#include <Rudy/Platform/OS/Windows/Threading/WindowsMutex.h>
namespace Rudy
{
	PlatformMutex* PlatformMutex::Create()
	{
		/*
		* Get platform os type
		*/
		PlatformOSType type = GetCurrentPlatform();

		/*
		* Catch platform os type
		*/
		switch (type)
		{
		case Rudy::PlatformOSType::Undefined:
			break;
		case Rudy::PlatformOSType::Windows:
			return new WindowsMutex();
			break;
		case Rudy::PlatformOSType::Linux:
			break;
		default:
			break;
		}
		return nullptr;
	}
	PlatformMutex::~PlatformMutex()
	{

	}
}