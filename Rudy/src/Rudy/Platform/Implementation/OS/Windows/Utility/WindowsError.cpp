#include "WindowsError.h"
#include <system_error>
#include <Windows.h>

namespace Rudy
{
	String PlatformError::GetLastOSError()
	{
		DWORD errorMessageID = GetLastError();
		return std::system_category().message(errorMessageID).c_str();
	}
}