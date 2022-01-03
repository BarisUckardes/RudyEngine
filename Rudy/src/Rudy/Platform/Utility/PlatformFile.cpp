#include "PlatformFile.h"
#include <Rudy/Platform/OS/PlatformOSDetection.h>
#include <Rudy/Platform/OS/Windows/Utility/WindowsFile.h>
namespace Rudy
{
	bool PlatformFile::IsFileExists(const String& path)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsFile::IsFileExists(path);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return false;
	}
	bool PlatformFile::CreateNewFile(const String& path)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsFile::CreateNewFile(path);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
	}
	bool PlatformFile::DeleteExistingFile(const String& path)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsFile::DeleteExistingFile(path);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
	}
	bool PlatformFile::WriteToFileText(const String& path, const String& content)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsFile::WriteToFileText(path,content);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
	}
	bool PlatformFile::WriteToExistingFile(const String& path, const String& content)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsFile::WriteToExistingFile(path,content);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
	}
	bool PlatformFile::ReadFromFile(const String& path, String& contentOut)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsFile::ReadFromFile(path,contentOut);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
	}
	bool PlatformFile::GetFileLength(const String& path, unsigned int& sizeOut)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsFile::GetFileLength(path,sizeOut);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
	}
	bool PlatformFile::GetFileExtension(const String& path, String& extensionOut)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsFile::GetFileExtension(path,extensionOut);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
	}
}