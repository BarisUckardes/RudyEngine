#pragma once
#include <Rudy/Platform/Threading/PlatformMutex.h>

namespace Rudy
{
	class RUDY_API WindowsMutex : public PlatformMutex
	{
	public:
		WindowsMutex();
		virtual ~WindowsMutex() override;

		// Inherited via PlatformMutex
		virtual void Lock() override;
		virtual void Release() override;
		//virtual bool TryLock() override;
	private:
		void* m_MutexHandle;
	};


}