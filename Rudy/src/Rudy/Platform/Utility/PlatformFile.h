#pragma once
#include <Rudy/Memory/String.h>
namespace Rudy
{
	class ByteBlock;
	/// <summary>
	/// Contains platform agnostic file actions
	/// </summary>
	class RUDY_API PlatformFile
	{
	public:
		PlatformFile() = delete;
		~PlatformFile() = delete;
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
		static bool Write(const String& path, const String& content);

		/// <summary>
		/// Creates and writes text to file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="content"></param>
		/// <returns></returns>
		static bool Write(const String& path, const Rudy::ByteBlock& byteBlock);

		/// <summary>
		/// Opens and appends to binary file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="bytes"></param>
		/// <returns></returns>
		static bool WriteAppend(const String& path, const Rudy::ByteBlock& byteBlock);

		/// <summary>
		/// Writes to an existing file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="content"></param>
		/// <returns></returns>
		static bool WriteToExisting(const String& path, const String& content);

		/// <summary>
		/// Reads the file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="contentOut"></param>
		/// <returns></returns>
		static bool Read(const String& path, String& contentOut);

		/// <summary>
		/// Reads the file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="contentOut"></param>
		/// <returns></returns>
		static bool Read(const String& path, Rudy::ByteBlock& byteBlock);

		/// <summary>
		/// Reads the file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="start"></param>
		/// <param name="end"></param>
		/// <param name="contentOut"></param>
		/// <returns></returns>
		static bool Read(const String& path, unsigned long start, unsigned long end, Rudy::ByteBlock& byteBlock);

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
		static bool GetFileExtension(const String& path, String& extensionOut);

		/// <summary>
		/// Returns the file name from the path
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		static String GetFileNameFromPath(const String& path);
	};
}