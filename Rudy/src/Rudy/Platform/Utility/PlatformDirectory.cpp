#include "PlatformDirectory.h"
#include <Rudy/Platform/OS/PlatformOSDetection.h>
#include <Rudy/Platform/OS/Windows/Utility/WindowsDirectory.h>
#include <stdio.h>
namespace Rudy
{
	bool PlatformDirectory::CreateDirectory(const String& path)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsDirectory::CreateDirectory0(path);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return false;
	}
	bool PlatformDirectory::DeleteDirectory(const String& path)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsDirectory::DeleteDirectory(path);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return false;
	}
	bool PlatformDirectory::GetItemNameFromDirectory(const String& path, String& itemName)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsDirectory::GetItemNameFromDirectory(path,itemName);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return false;
	}
	bool PlatformDirectory::GetAllItemsInDirectory(const String& path, Array<String>& itemsOut)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsDirectory::GetAllItemsInDirectory(path,itemsOut);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return false;
	}
	bool PlatformDirectory::GetFoldersInDirectory(const String& path, Array<String>& foldersOut)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsDirectory::GetFoldersInDirectory(path,foldersOut);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return false;
	}
	bool PlatformDirectory::GetFilesInDirectory(const String& path, Array<String>& filesOut)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsDirectory::GetFilesInDirectory(path,filesOut);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return false;
	}
	bool PlatformDirectory::GetFilesInDirectoryViaExtension(const String& path, const String& extension, Array<String>& filesOut)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsDirectory::GetFilesInDirectoryViaExtension(path,extension,filesOut);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return false;
	}
	bool PlatformDirectory::IsDirectoryExists(const String& path)
	{
		PlatformOSType platformType = GetCurrentPlatform();
		switch (platformType)
		{
			case Rudy::PlatformOSType::Undefined:
				break;
			case Rudy::PlatformOSType::Windows:
				return WindowsDirectory::IsDirectoryExists(path);
				break;
			case Rudy::PlatformOSType::Linux:
				break;
			default:
				break;
		}
		return false;
	}
	String PlatformDirectory::GetFolderNameFromPath(const String& path)
	{
		/*
		* Get last index of a slash
		*/
		const unsigned int lastIndex = path.FindLastIndex("/",0);

		/*
		* Get substring
		*/
		return path.GetSubset(lastIndex+1, path.GetCursor() - lastIndex);
	}
}