#include "Application.h"
#include <Rudy/Windowing/Window.h>
#include <stdio.h>
#include <Rudy/Events/Delegate.h>
#include <Rudy/Application/ApplicationModule.h>
namespace Rudy
{
	Window* Application::GetWindow() const
	{
		return m_Window;
	}
	void Application::Run()
	{
		/*
		* Create state
		*/
		bool hasExitRequest = false;

		/*
		* Initialize session
		*/

		/*
		* Attach pending modules
		*/
		for (int i = 0; i < m_PendingModules.GetCursor(); i++)
		{
			/*
			* Get the module
			*/
			ApplicationModule* module = m_PendingModules[i];

			/*
			* Attach the module
			*/
			module->OnAttach();

			/*
			* Register module to the main loop
			*/
			m_Modules.Add(module);
		}
		m_PendingModules.Clear();

		/*
		* Application loop
		*/
		while (!hasExitRequest)
		{
			/*
			* Poll buffered window events
			*/
			m_Window->PollBufferedEvents();

			/*
			* Broadcast events
			*/

			/*
			* Update modules
			*/
			for (int i = 0; i < m_Modules.GetCursor(); i++)
			{
				m_Modules[i]->OnUpdate();
			}

			/*
			* Validate window
			*/
			if (!m_Window->IsAlive())
				hasExitRequest = true;

			/*
			* Validate session
			*/

		}

		/*
		* Detach all modules
		*/
		for (int i = 0; i < m_Modules.GetCursor(); i++)
		{
			m_Modules[i]->OnDetach();
		}

		/*
		* Delete session
		*/

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
		m_ApplicationWindowEventDelegate = new Delegate<void,Event*>(RUDY_BIND_EVENT(this, Application::OnEventReceived));
		m_Window->RegisterCallBack(m_ApplicationWindowEventDelegate);

	}
	void Application::OnEventReceived(Event* event)
	{
		m_BufferedEvents.Add(event);
	}
}
