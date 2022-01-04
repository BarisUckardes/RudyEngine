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
		m_Size = Vector2i(sizeX, sizeY);
		m_Offset = Vector2i(offsetX, offsetY);
	}

	Vector2i Window::GetSize() const
	{
		return m_Size;
	}

	Vector2i Window::GetOffset() const
	{
		return m_Offset;
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
		delete event;
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
		m_Size = newSize;
	}
	void Window::OnWindowClosedEvent()
	{

	}
	void Window::OnWindowOffsetChanged(const Vector2i& newOffset)
	{
		m_Offset = newOffset;
	}
}