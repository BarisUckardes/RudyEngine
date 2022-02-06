#include "WindowsPaths.h"
#include <Windows.h>
#include <Psapi.h>
#include <string>
#include <Shlwapi.h>
#include <ShlObj_core.h>
#pragma comment(lib, "shlwapi.lib")
#define SPECIAL_FOLDER_PATH_SIZE 256
namespace Rudy
{
	String PlatformPaths::s_ExecutionPath = "";
	String PlatformPaths::GetExecutablePath()
	{
		return s_ExecutionPath;
	}

	String PlatformPaths::GetDomainPath()
	{
		return String();
	}

	String PlatformPaths::GetAppDataPath()
	{
		char* buffer = new char[SPECIAL_FOLDER_PATH_SIZE];
		SHGetSpecialFolderPathA(NULL, buffer, CSIDL_APPDATA, false);
		return String(buffer);

	}

	String PlatformPaths::GetAppDataLocalPath()
	{
		char* buffer = new char[SPECIAL_FOLDER_PATH_SIZE];
		SHGetSpecialFolderPathA(NULL, buffer, CSIDL_LOCAL_APPDATA, false);
		return String(buffer);
	}

	String PlatformPaths::GetProgramFilesPath()
	{
		char* buffer = new char[SPECIAL_FOLDER_PATH_SIZE];
		SHGetSpecialFolderPathA(NULL, buffer, CSIDL_PROGRAM_FILES, false);
		return String(buffer);
	}

	String PlatformPaths::GetDesktopPath()
	{
		char* buffer = new char[SPECIAL_FOLDER_PATH_SIZE];
		SHGetSpecialFolderPathA(NULL, buffer, CSIDL_DESKTOP, false);
		return String(buffer);
	}

	String PlatformPaths::GetDocumentsPath()
	{
		char* buffer = new char[SPECIAL_FOLDER_PATH_SIZE];
		SHGetSpecialFolderPathA(NULL, buffer, CSIDL_MYDOCUMENTS, false);
		return String(buffer);

	}

	void PlatformPaths::SetExecutionPath(const String& executionPath)
	{
		s_ExecutionPath = executionPath;
	}

}