#pragma once
#include <Rudy/Memory/String.h>
namespace Rudy
{
	/// <summary>
	/// Contains platform agnostic file actions
	/// </summary>
	class RUDY_API WindowsFile
	{
	public:
		WindowsFile() = delete;
		~WindowsFile() = delete;
		/// <summary>
		/// Returns whether the file is exists
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		static bool IsFileExists(const String& path);

		/// <summary>
		/// Creates a new file
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		static bool CreateNewFile(const String& path);

		/// <summary>
		/// Deletes the existing file
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		static bool DeleteExistingFile(const String& path);

		/// <summary>
		/// Creates and writes text to file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="content"></param>
		/// <returns></returns>
		static bool WriteToFileText(const String& path, const String& content);

		/// <summary>
		/// Creates and writes text to file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="content"></param>
		/// <returns></returns>
		static bool WriteToFileBytes(const String& path, const Array<unsigned char>& content);

		/// <summary>
		/// Writes to an existing file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="content"></param>
		/// <returns></returns>
		static bool WriteToExistingFile(const String& path, const String& content);

		/// <summary>
		/// Reads the file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="contentOut"></param>
		/// <returns></returns>
		static bool ReadText(const String& path, String& contentOut);

		/// <summary>
		/// Reads the file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="contentOut"></param>
		/// <returns></returns>
		static bool ReadBytes(const String& path, Array<unsigned char>& contentOut);

		/// <summary>
		/// Reads the file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="contentOut"></param>
		/// <returns></returns>
		static bool ReadBytes(const String& path,unsigned long startByte,unsigned long endByte, Array<unsigned char>& contentOut);

		/// <summary>
		/// Returns the file size in length
		/// </summary>
		/// <param name="path"></param>
		/// <param name="sizeOut"></param>
		/// <returns></returns>
		static bool GetFileLength(const String& path, unsigned long& sizeOut);

		/// <summary>
		/// Returns the file extension
		/// </summary>
		/// <param name="path"></param>
		/// <param name="extension"></param>
		/// <returns></returns>
		static bool GetFileExtension(const String& path, String& extension);
	};
}
