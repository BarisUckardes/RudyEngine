#pragma once
#include <Rudy/Memory/String.h>

namespace Rudy
{
#ifdef RUDY_OS_WINDOWS
	class RUDY_API PlatformPaths
	{
		friend class Application;
	public:
		PlatformPaths() = default;
		~PlatformPaths() = default;

		/// <summary>
		/// Returns the path of this running application
		/// </summary>
		/// <returns></returns>
		static String GetExecutablePath();

		/// <summary>
		/// Returns the domain content path of the application
		/// </summary>
		/// <returns></returns>
		static String GetDomainPath();

		/// <summary>
		/// Returns appdata path 
		/// </summary>
		/// <returns></returns>
		static String GetAppDataPath();

		/// <summary>
		/// Returns appdatalocal path
		/// </summary>
		/// <returns></returns>
		static String GetAppDataLocalPath();

		/// <summary>
		/// Returns the program files path
		/// </summary>
		/// <returns></returns>
		static String GetProgramFilesPath();

		/// <summary>
		/// Returns the desktop path
		/// </summary>
		/// <returns></returns>
		static String GetDesktopPath();

		/// <summary>
		/// Returns the documents path
		/// </summary>
		/// <returns></returns>
		static String GetDocumentsPath();

	private:
		static void SetExecutionPath(const String& executionPath);
		static String s_ExecutionPath;
	};
#endif
}