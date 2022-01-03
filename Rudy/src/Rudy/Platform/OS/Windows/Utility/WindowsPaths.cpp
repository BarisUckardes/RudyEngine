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
	String WindowsPaths::GetExecutablePath()
	{
		/*
		* Collect path
		*/
		TCHAR path[MAXCHAR];
		GetModuleFileName(NULL, path, MAX_PATH);

		/*
		* Remove file name
		*/
		PathRemoveFileSpec(path);

		/*
		* Wide string to string
		*/
		std::wstring ws(path);
		std::string str(ws.begin(), ws.end());


		return String(str.c_str());
	}

	String WindowsPaths::GetDomainPath()
	{
		return String();
	}

	String WindowsPaths::GetAppDataPath()
	{
		char* buffer = new char[SPECIAL_FOLDER_PATH_SIZE];
		SHGetSpecialFolderPathA(NULL, buffer, CSIDL_APPDATA, false);
		return String(buffer);
	}

	String WindowsPaths::GetAppDataLocalPath()
	{
		char* buffer = new char[SPECIAL_FOLDER_PATH_SIZE];
		SHGetSpecialFolderPathA(NULL, buffer, CSIDL_LOCAL_APPDATA, false);
		return String(buffer);
	}

	String WindowsPaths::GetProgramFilesPath()
	{
		char* buffer = new char[SPECIAL_FOLDER_PATH_SIZE];
		SHGetSpecialFolderPathA(NULL, buffer, CSIDL_PROGRAMS, false);
		return String(buffer);
	}

	String WindowsPaths::GetDesktopPath()
	{
		char* buffer = new char[SPECIAL_FOLDER_PATH_SIZE];
		SHGetSpecialFolderPathA(NULL, buffer, CSIDL_DESKTOP, false);
		return String(buffer);
	}

}