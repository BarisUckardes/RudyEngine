#include "Application.h"
#include <Rudy/Windowing/Window.h>
#include <stdio.h>
#include <Rudy/Events/Delegate.h>
#include <Rudy/Application/ApplicationModule.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Application/ApplicationSession.h>
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
		* Create application session
		*/
		m_Session = new ApplicationSession();

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
			* Set session
			*/
			module->SetOwnerSession(m_Session);

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
			* Swap buffers
			*/
			m_Window->GetGraphicsDevice()->Swapbuffers();

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
		m_ApplicationWindowEventDelegate = new Delegate<void,Event*>(RUDY_BIND_EVENT(Application::OnEventReceived));
		m_Window->RegisterCallBack(m_ApplicationWindowEventDelegate);

	}
	void Application::OnEventReceived(Event* event)
	{
		for (int i = m_Modules.GetCursor() - 1; i >= 0; i--)
		{
			/*
			* Broadcast the event to the module
			*/
			m_Modules[i]->OnReceiveApplicationEvent(event);

			/*
			* Validate handled
			*/
			if (event->IsHandled())
				break;
			
		}
		m_BufferedEvents.Add(event);
	}
}
