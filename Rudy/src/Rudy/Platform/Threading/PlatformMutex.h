#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Platform Os agnostic mutex class
	/// </summary>
	class RUDY_API PlatformMutex
	{
	public:
		static PlatformMutex* Create();
		virtual ~PlatformMutex() = 0;

		/// <summary>
		/// Locks this mutex for access
		/// </summary>
		virtual void Lock() = 0;

		/// <summary>
		/// Releases the lockdown on this mutex
		/// </summary>
		virtual void Release() = 0;

		/// <summary>
		/// Tries to lock this mutex and returns the lock state
		/// </summary>
		/// <returns></returns>
		//virtual bool TryLock() = 0;
	protected:
		PlatformMutex() = default;
	};


}