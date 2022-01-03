#pragma once
#include <Rudy/Memory/String.h>

namespace Rudy
{
	class RUDY_API PlatformError
	{
	public:
		PlatformError() = delete;
		~PlatformError() = delete;
		
		static String GetLastOSError();
	};


}