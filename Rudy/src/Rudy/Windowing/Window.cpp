#include "Window.h"
#include <Rudy/Platform/OS/Windows/Window/WindowsWindow.h>
#include <Rudy/Platform/Graphics/GraphicsAPIType.h>
#include <Rudy/Events/Window/WindowResizedEvent.h>
namespace Rudy
{
	Window* Window::Create(const String& title,
		const unsigned int offsetX, const unsigned int offsetY,
		unsigned int sizeX, unsigned int sizeY)
	{
		return new WindowsWindow(title,offsetX,offsetY,sizeX,sizeY);
	}

	Window::Window(const String& title, const unsigned int offsetX, const unsigned int offsetY, unsigned int sizeX, unsigned int sizeY)
	{
		/*
		* Create window event callback delegate
		*/
		m_WindowEventCallback = new Delegate<void, Event*>(RUDY_BIND_EVENT(Window::OnBroadcastEvent));

		/*
		* Set window propertie
		*/
		m_OffsetX = offsetX;
		m_OffsetY = offsetY;
		m_Width = sizeX;
		m_Height = sizeY;
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

	bool Window::IsAlive() const
	{
		return m_WindowAlive;
	}

	GraphicsDevice* Window::GetGraphicsDevice() const
	{
		return m_GraphicsDevice;
	}

	void Window::RegisterCallBack(Delegate<void, Event*> functionPtr)
	{
		m_Callbacks.Add(functionPtr);
	}

	void Window::RemoveCallBack(Delegate<void, Event*> functionPtr)
	{
		m_Callbacks.Remove(functionPtr);
	}

	void Window::OnBroadcastEvent(Event* event)
	{
		/*
		* Collect window property events
		*/
		if (event->GetEventType() == EventType::WindowResized)
		{
			OnWindowResizeEvent(((WindowResizedEvent*)event)->GetSize());
		}
		/*
		* Iterate each registered callbacks and fire them
		*/
		for (int i = 0; i < m_Callbacks.GetCursor(); i++)
		{
			m_Callbacks[i].Invoke(event);
		}
	}

	void Window::SetAliveState(bool state)
	{
		m_WindowAlive = state;
	}

	void Window::SetGraphicsDevice(GraphicsDevice* device)
	{
		m_GraphicsDevice = device;
	}

	Delegate<void, Event*>* Window::GetWindowEventDelegate() const
	{
		return m_WindowEventCallback;
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