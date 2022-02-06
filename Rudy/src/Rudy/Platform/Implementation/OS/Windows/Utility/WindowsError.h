#pragma once
#include <Rudy/Memory/String.h>

namespace Rudy
{
#ifdef RUDY_OS_WINDOWS
	class RUDY_API PlatformError
	{
	public:
		PlatformError() = delete;
		~PlatformError() = delete;

		static String GetLastOSError();
	};
#endif

}