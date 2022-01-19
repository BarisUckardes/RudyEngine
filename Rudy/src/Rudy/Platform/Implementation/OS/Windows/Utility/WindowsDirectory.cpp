#include "WindowsDirectory.h"
#include <comdef.h>
#include <Windows.h>
#include <mbstring.h>
#include <memory>
#include <string>
#include <system_error>
#include <Shlwapi.h>
#include <Rudy/Platform/Utility/PlatformFile.h>

namespace Rudy
{
	bool WindowsDirectory::CreateDirectory0(const String& path)
	{
		return CreateDirectoryA(*path, NULL);
	}
	bool WindowsDirectory::DeleteDirectory(const String& path)
	{
		/*
		* Validate path
		*/
		if (IsDirectoryExists(path))
		{
			/*
			* Get sub items
			*/
			Array<String> items;
			GetAllItemsInDirectory(path, items);

			/*
			* Validate sub items
			*/
			if (items.GetCursor() > 0) // has sub items
			{
				/*
				* Iterate each item in directory
				*/
				for (unsigned int itemIndex = 0; itemIndex < items.GetCursor(); itemIndex++)
				{
					/*
					* Get item path
					*/
					const String itemPath = items[itemIndex];

					/*
					* Validate if its a file
					*/
					bool isFile = !IsDirectoryExists(itemPath);

					/*
					* Execute proper action
					*/
					if (isFile) // if its a file jusst delete it
					{
						PlatformFile::DeleteExistingFile(itemPath);
					}
					else
					{
						DeleteDirectory(itemPath);
					}
				}
			}

			/*
			* Delete actual folder
			*/
			RemoveDirectoryA(*path);

			return true;
		}
		else
		{
			return false;
		}
	}
	bool WindowsDirectory::GetItemNameFromDirectory(const String& path, String& itemName)
	{
		itemName = PathFindFileNameA(*path);
		return true;
	}
	bool WindowsDirectory::GetAllItemsInDirectory(const String& path, Array<String>& itemsOut)
	{
		/*
		* Create concrete path DUMMY
		*/
		String completePath = path + "*";

		/*
		* Get file handle
		*/
		WIN32_FIND_DATAA fileFindData;
		HANDLE fileHandle = FindFirstFileA(*completePath, &fileFindData);

		/*
		* Validate file handle
		*/
		if (fileHandle != INVALID_HANDLE_VALUE)
		{
			do
			{
				/*
				* Get folder name
				*/
				String folderName = fileFindData.cFileName;

				/*
				* Reject "." and ".."
				*/
				if (folderName == "." || folderName == "..")
					continue;

				/*
				* Register folder name
				*/
				itemsOut.Add(path + folderName);

			} while (FindNextFileA(fileHandle, &fileFindData));

			/*
			* Close find file view
			*/
			FindClose(fileHandle);
			return true;
		}

		/*
		* Close find file view
		*/
		FindClose(fileHandle);
		return false;
	}
	bool WindowsDirectory::GetFoldersInDirectory(const String& path, Array<String>& foldersOut)
	{
		/*
		* Get all file names
		*/
		Array<String> totalItems;
		bool getItemsSuccess = GetAllItemsInDirectory(path, totalItems);

		/*
		* Validate get file names succcess
		*/
		if (!getItemsSuccess)
		{
			return false;
		}

		/*
		* Collect the ones with the extension
		*/
		for (unsigned int fileIndex = 0; fileIndex < totalItems.GetCursor(); fileIndex++)
		{
			/*
			* Validate folder
			*/
			if (IsDirectoryExists(totalItems[fileIndex]))
			{
				foldersOut.Add(totalItems[fileIndex]);
			}
		}

		return true;
	}
	bool WindowsDirectory::GetFilesInDirectory(const String& path, Array<String>& filesOut)
	{
		/*
		* Get all file names
		*/
		Array<String> totalFiles;
		bool getFilesSuccess = GetAllItemsInDirectory(path, totalFiles);

		/*
		* Validate get file names succcess
		*/
		if (!getFilesSuccess)
		{
			return false;
		}

		/*
		* Collect the ones with the extension
		*/
		for (unsigned int fileIndex = 0; fileIndex < totalFiles.GetCursor(); fileIndex++)
		{
			/*
			* Validate folder
			*/
			if (!IsDirectoryExists(totalFiles[fileIndex]))
			{
				filesOut.Add(totalFiles[fileIndex]);
			}
		}

		return true;
	}
	bool WindowsDirectory::GetFilesInDirectoryViaExtension(const String& path, const String& extension, Array<String>& filesOut)
	{
		/*
		* Get all file names
		*/
		Array<String> totalFiles;
		bool getFilesSuccess = GetAllItemsInDirectory(path, totalFiles);

		/*
		* Validate get file names succcess
		*/
		if (!getFilesSuccess)
		{
			return false;
		}

		/*
		* Collect the ones with the extension
		*/
		for (unsigned int fileIndex = 0; fileIndex < totalFiles.GetCursor(); fileIndex++)
		{
			/*
			* Validate folder
			*/
			if (!IsDirectoryExists(totalFiles[fileIndex]))
			{
				/*
				* Get extension
				*/
				String fileExtension;
				bool extensionPathValid = PlatformFile::GetFileExtension(totalFiles[fileIndex], fileExtension);

				/*
				* Validate extension extraction
				*/
				if (!extensionPathValid)
					continue;

				/*
				* Validate extension match
				*/
				if (fileExtension == extension)
					filesOut.Add(totalFiles[fileIndex]);
			}
		}
	}
	bool WindowsDirectory::IsDirectoryExists(const String& path)
	{
		/*
		* Get file diagnostic
		*/
		DWORD diagnostic = GetFileAttributesA(*path);

		/*
		* Validate diagnostics
		*/
		if (diagnostic != INVALID_FILE_ATTRIBUTES && diagnostic == FILE_ATTRIBUTE_DIRECTORY)
			return true;

		return false;
	}
	String WindowsDirectory::GetFolderNameFromPath(const String& path)
	{
		return String();
	}
}