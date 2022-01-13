#pragma once
#include <Rudy/Process/PlatformProcess.h>

namespace Rudy
{
	/// <summary>
	/// Platform process windows implementation
	/// </summary>
	class RUDY_API WindowsProcess : public PlatformProcess
	{
	public:
		WindowsProcess(const Array<String>& cmdArguments, const String& executablePath);
		virtual ~WindowsProcess() override;

		virtual void* GetNativeHandle() const override;
		virtual void StartCore() override;
		virtual void WaitForFinishCore() override;
		virtual void FinalizeCore() override;
	private:
		void* m_ProcessHandle;
		void* m_ThreadHandle;
	};

}
