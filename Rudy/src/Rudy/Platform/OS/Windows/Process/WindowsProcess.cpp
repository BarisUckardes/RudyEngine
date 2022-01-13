#include "WindowsProcess.h"
#include <windows.h>
#include <stdio.h>
#include <Rudy/Platform/Utility/PlatformError.h>
namespace Rudy
{
	WindowsProcess::WindowsProcess(const Array<String>& cmdArguments, const String& executablePath) : PlatformProcess(cmdArguments,executablePath)
	{

	}
	WindowsProcess::~WindowsProcess()
	{

	}
    void* WindowsProcess::GetNativeHandle() const
    {
        return nullptr;
    }
    void WindowsProcess::StartCore()
	{
        /*
        * Create start informations
        */
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        /*
        * Windows related size handles
        */
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        /*
        * Merge cmd commands
        */
        Array<String> cmdCommands;
        cmdCommands.Add(GetExecutablePath());
        cmdCommands.Add(GetCmdArguments());
        String concreteCmdCommands;
        for (int i = 0; i < cmdCommands.GetCursor(); i++)
            concreteCmdCommands += cmdCommands[i] + " ";

        /*
        * Convert char* to wchar*
        */
        const size_t cSize = strlen(*concreteCmdCommands) + 1;
        wchar_t* wc = new wchar_t[cSize];
        mbstowcs(wc, *concreteCmdCommands, cSize);

        /*
        * Starts the child process
        */
        if (!CreateProcess(
            NULL,   // No module name (use command line)
            wc,        // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            FALSE,          // Set handle inheritance to FALSE
            0,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory 
            &si,            // Pointer to STARTUPINFO structure
            &pi)           // Pointer to PROCESS_INFORMATION structure
            )
        {
            printf("CreateProcess failed (%s).\n", *PlatformError::GetLastOSError());
            return;
        }

        /*
        * Set windows handles
        */
        m_ProcessHandle = pi.hProcess;
        m_ThreadHandle = pi.hThread;
	}
	void WindowsProcess::WaitForFinishCore()
	{
        WaitForSingleObject(m_ProcessHandle, INFINITE);
	}
	void WindowsProcess::FinalizeCore()
	{
        CloseHandle(m_ProcessHandle);
        CloseHandle(m_ThreadHandle);
	}
}