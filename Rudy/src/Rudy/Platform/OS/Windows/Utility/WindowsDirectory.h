#pragma once
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{

	class RUDY_API WindowsDirectory
	{
	public:
		WindowsDirectory() = default;
		~WindowsDirectory() = default;

		/// <summary>
		/// Creates a new directory
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		static bool CreateDirectory0(const String& path);

		/// <summary>
		/// Deletes the specfied directory
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		static bool DeleteDirectory(const String& path);

		/// <summary>
		/// Returns the folder name of the directory
		/// </summary>
		/// <param name="path"></param>
		/// <param name="itemName"></param>
		/// <returns></returns>
		static bool GetItemNameFromDirectory(const String& path, String& itemName);

		/// <summary>
		/// Returns all the items in the specified directory
		/// </summary>
		/// <param name="path"></param>
		/// <param name="itemName"></param>
		/// <returns></returns>
		static bool GetAllItemsInDirectory(const String& path, Array<String>& itemsOut);

		/// <summary>
		/// Returns all the folders in the specified directory
		/// </summary>
		/// <param name="path"></param>
		/// <param name="foldersOut"></param>
		/// <returns></returns>
		static bool GetFoldersInDirectory(const String& path, Array<String>& foldersOut);

		/// <summary>
		/// Returns all the files in the specified diretory
		/// </summary>
		/// <param name="path"></param>
		/// <param name="filesOut"></param>
		/// <returns></returns>
		static bool GetFilesInDirectory(const String& path, Array<String>& filesOut);

		/// <summary>
		/// Returns all the files in the directory via the specified extension
		/// </summary>
		/// <param name="path"></param>
		/// <param name="extension"></param>
		/// <param name="filesOut"></param>
		/// <returns></returns>
		static bool GetFilesInDirectoryViaExtension(const String& path, const String& extension, Array<String>& filesOut);

		/// <summary>
		/// Returns whethe the directory is exist or not 
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		static bool IsDirectoryExists(const String& path);
	};
}