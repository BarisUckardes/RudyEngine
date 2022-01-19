#pragma once
#include <Rudy/Memory/String.h>

namespace Rudy
{

	class RUDY_API WindowsError
	{
	public:
		WindowsError() = delete;
		~WindowsError() = delete;

		static String GetLastOSError();
	};

}