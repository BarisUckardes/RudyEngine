#include "PlatformPaths.h"
#include <Rudy/Platform/OS/PlatformOSDetection.h>
#include <Rudy/Platform/OS/Windows/Utility/WindowsPaths.h>

namespace Rudy
{
	String PlatformPaths::GetExecutablePath()
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsPaths::GetExecutablePath();
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return String();
	}
	String PlatformPaths::GetDomainPath()
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsPaths::GetExecutablePath();
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return String();
	}
	String PlatformPaths::GetAppDataPath()
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsPaths::GetAppDataPath();
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return String();
	}
	String PlatformPaths::GetAppDataLocalPath()
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsPaths::GetAppDataLocalPath();
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return String();
	}
	String PlatformPaths::GetProgramFilesPath()
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsPaths::GetProgramFilesPath();
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return String();
	}
	String PlatformPaths::GetDesktopPath()
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsPaths::GetDesktopPath();
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return String();
	}
}