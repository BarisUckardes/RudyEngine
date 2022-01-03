#include "WindowsError.h"
#include <system_error>
#include <Windows.h>

namespace Rudy
{
	String WindowsError::GetLastOSError()
	{
		DWORD errorMessageID = GetLastError();
		return std::system_category().message(errorMessageID).c_str();
	}
}