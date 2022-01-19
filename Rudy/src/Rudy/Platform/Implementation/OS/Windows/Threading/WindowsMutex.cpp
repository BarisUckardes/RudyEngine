#include "WindowsMutex.h"
#include <windows.h>

namespace Rudy
{
	WindowsMutex::WindowsMutex()
	{
		m_MutexHandle = CreateMutex(NULL, FALSE, NULL);
	}
	WindowsMutex::~WindowsMutex()
	{
		CloseHandle(m_MutexHandle);
		m_MutexHandle = nullptr;
	}
	void WindowsMutex::Lock()
	{
		WaitForSingleObject(m_MutexHandle, NULL);
	}
	void WindowsMutex::Release()
	{
		ReleaseMutex(m_MutexHandle);
	}
	//bool WindowsMutex::TryLock()
	//{
	//	return OpenMutex(SYNCHRONIZE, FALSE, NULL);
	//}
}