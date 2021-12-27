#include "Window.h"
#include <Rudy/Platform/OS/Windows/WindowsWindow.h>
namespace Rudy
{
	Window* Window::Create(const String& title, const unsigned int offsetX, const unsigned int offsetY, unsigned int sizeX, unsigned int sizeY)
	{
		return new WindowsWindow(title,offsetX,offsetY,sizeX,sizeY);
	}

	Window::Window(const String& title, const unsigned int offsetX, const unsigned int offsetY, unsigned int sizeX, unsigned int sizeY)
	{
		
	}

	unsigned int Window::GetWidth() const
	{
		return m_Width;
	}

	unsigned int Window::GetHeight() const
	{
		return m_Height;
	}

	String Window::GetTitle() const
	{
		return m_Title;
	}

	unsigned int Window::GetOffsetX() const
	{
		return m_OffsetX;
	}

	unsigned int Window::GetOffsetY() const
	{
		return m_OffsetY;
	}

	void Window::RegisterCallBack(Delegate<void, Event&>* functionPtr)
	{
		m_Callbacks.Add(functionPtr);
	}

	void Window::RemoveCallBack(Delegate<void, Event&>* functionPtr)
	{
		m_Callbacks.Remove(functionPtr);
	}

	void Window::OnEmitPlatformEvent(Event& event)
	{
		/*
		* Catch window events
		*/

		/*
		* Iterate each registered callbacks and fire them
		*/
		for (int i = 0; i < m_Callbacks.GetCursor(); i++)
		{
			m_Callbacks[i]->Invoke(event);
		}
	}

	Window::~Window()
	{
		/*
		* Remove all the callbacks
		*/
		for (int i = 0; i < m_Callbacks.GetCursor(); i++)
		{
			//delete m_Callbacks[i];
		}
		m_Callbacks.Clear();
	}
	void Window::OnWindowResizeEvent(const Vector2i& newSize)
	{
		m_Width = newSize.X;
		m_Height = newSize.Y;
	}
	void Window::OnWindowClosedEvent()
	{
		m_WindowAlive = false;
	}
	void Window::OnWindowOffsetChanged(const Vector2i& newOffset)
	{
		m_OffsetX = newOffset.X;
		m_OffsetY = newOffset.Y;
	}
}