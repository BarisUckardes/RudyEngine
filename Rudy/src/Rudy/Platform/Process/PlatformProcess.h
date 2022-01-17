#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Platform/Process/PlatformProcessState.h>
namespace Rudy
{
	/// <summary>
	/// Platform agnostic process class
	/// </summary>
	class RUDY_API PlatformProcess
	{
	public:
		/// <summary>
		/// Creates process for the current platform
		/// </summary>
		/// <returns></returns>
		static PlatformProcess* Create(const Array<String>& cmdArguments, const String& executablePath);
		virtual ~PlatformProcess() = default;

		/// <summary>
		/// Returns the os dependent native handle
		/// </summary>
		/// <returns></returns>
		virtual void* GetNativeHandle() const = 0;

		/// <summary>
		/// Starts this process
		/// </summary>
		void Start();

		/// <summary>
		/// Waits for this process to finish
		/// </summary>
		void WaitForFinish();

		/// <summary>
		/// Force stops this process
		/// </summary>
		void Finalize();
	protected:
		PlatformProcess(const Array<String>& cmdArguments, const String& executablePath);

		/// <summary>
		/// Returns the cmd arguments(executable path excluded)
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<String> GetCmdArguments() const;

		/// <summary>
		/// Returns the executable path
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetExecutablePath() const;

		/// <summary>
		/// Start os implementation
		/// </summary>
		virtual void StartCore() = 0;

		/// <summary>
		/// Wait for finish os implementation
		/// </summary>
		virtual void WaitForFinishCore() = 0;

		/// <summary>
		/// Force stop os implementation
		/// </summary>
		virtual void FinalizeCore() = 0;
	private:
		Array<String> m_CmdArguments;
		String m_ExecutablePath;
		PlatformProcessState m_State;

	};


}