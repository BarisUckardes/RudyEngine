#include "PlatformProcess.h"
#include <Rudy/Platform/OS/PlatformOSDetection.h>
#include <Rudy/Platform/OS/Windows/Process/WindowsProcess.h>
namespace Rudy
{
	PlatformProcess::PlatformProcess(const Array<String>& cmdArguments, const String& executablePath)
	{
		m_CmdArguments = cmdArguments;
		m_ExecutablePath = executablePath;
		m_State = PlatformProcessState::Initialized;
	}
	Array<String> PlatformProcess::GetCmdArguments() const
	{
		return m_CmdArguments;
	}
	String PlatformProcess::GetExecutablePath() const
	{
		return m_ExecutablePath;
	}
	PlatformProcess* PlatformProcess::Create(const Array<String>& cmdArguments, const String& executablePath)
	{
		/*
		* Get current platform
		*/
		PlatformOSType osType = GetCurrentPlatform();

		/*
		* Catch current platform
		*/
		PlatformProcess* process = nullptr;
		switch (osType)
		{
		case Rudy::PlatformOSType::Undefined:
			break;
		case Rudy::PlatformOSType::Windows:
			process = new WindowsProcess(cmdArguments,executablePath);
			break;
		case Rudy::PlatformOSType::Linux:
			break;
		default:
			break;
		}
		return process;
	}
	void PlatformProcess::Start()
	{
		/*
		* Call os start implementation
		*/
		StartCore();

		/*
		* Set state
		*/
		m_State = PlatformProcessState::Running;
	}
	void PlatformProcess::WaitForFinish()
	{
		/*
		* Set state
		*/
		m_State = PlatformProcessState::WaitingForFinish;

		/*
		* Call os implementation
		*/
		WaitForFinishCore();
	}
	void PlatformProcess::Finalize()
	{
		/*
		* Call os implementaion
		*/
		FinalizeCore();

		/*
		* Set state
		*/
		m_State = PlatformProcessState::Finalized;
	}
}