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
	bool PlatformFile::Write(const String& path, const String& content)
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
	bool PlatformFile::Write(const String& path, const ByteBlock& byteBlock)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
		case Rudy::PlatformOSType::Undefined:
			break;
		case Rudy::PlatformOSType::Windows:
			return WindowsFile::WriteToFileBytes(path, byteBlock);
			break;
		case Rudy::PlatformOSType::Linux:
			break;
		default:
			break;
		}
	}
	bool PlatformFile::WriteAppend(const String& path, const ByteBlock& byteBlock)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
		case Rudy::PlatformOSType::Undefined:
			break;
		case Rudy::PlatformOSType::Windows:
			return WindowsFile::WriteToFileAppendBytes(path, byteBlock);
			break;
		case Rudy::PlatformOSType::Linux:
			break;
		default:
			break;
		}
	}
	bool PlatformFile::WriteToExisting(const String& path, const String& content)
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
	bool PlatformFile::Read(const String& path, String& contentOut)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsFile::ReadText(path,contentOut);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
	}

	bool PlatformFile::Read(const String& path, ByteBlock& byteBlock)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
		case Rudy::PlatformOSType::Undefined:
			break;
		case Rudy::PlatformOSType::Windows:
			return WindowsFile::ReadBytes(path, byteBlock);
			break;
		case Rudy::PlatformOSType::Linux:
			break;
		default:
			break;
		}
	}
	bool PlatformFile::Read(const String& path, unsigned long startByte, unsigned long endByte, ByteBlock& byteBlock)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
		case Rudy::PlatformOSType::Undefined:
			break;
		case Rudy::PlatformOSType::Windows:
			return WindowsFile::ReadBytes(path,startByte,endByte, byteBlock);
			break;
		case Rudy::PlatformOSType::Linux:
			break;
		default:
			break;
		}
	}
	bool PlatformFile::GetFileLength(const String& path, unsigned long& sizeOut)
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