#include "PlatformPaths.h"
#include <Rudy/Platform/Implementation/OS/PlatformOSDetection.h>
#include <Rudy/Platform/Implementation/OS/Windows/Utility/WindowsPaths.h>

namespace Rudy
{
	String PlatformPaths::s_ExecutionPath = "Undefined executionPath";
	String PlatformPaths::GetExecutablePath()
	{
		return s_ExecutionPath;
	}
	String PlatformPaths::GetDomainPath()
	{
		return GetExecutablePath() + "/Domain";
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
	String PlatformPaths::GetDocumentsPath()
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
		case Rudy::PlatformOSType::Undefined:
			break;
		case Rudy::PlatformOSType::Windows:
			return WindowsPaths::GetDocumentsPath();
			break;
		case Rudy::PlatformOSType::Linux:
			break;
		default:
			break;
		}
		return String();
	}
	void PlatformPaths::SetExecutionPath(const String& executionPath)
	{
		s_ExecutionPath = executionPath;
	}
}