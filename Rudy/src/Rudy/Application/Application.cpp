#include "Application.h"
#include <Rudy/Windowing/Window.h>
#include <stdio.h>
#include <Rudy/Events/Delegate.h>
namespace Rudy
{
	Window* Application::GetWindow() const
	{
		return m_Window;
	}
	void Application::SubmitWindow(Window* window)
	{
		/*
		* Set window
		*/
		m_Window = window;

		/*
		* Register event
		*/
		m_WindowEventDelegate = new Delegate<void,Event&>(RUDY_BIND_EVENT(this, Application::OnEventReceived));
		m_Window->RegisterCallBack(m_WindowEventDelegate);
	}
}
