#include "WindowGUIModule.h"
#include <Bite/GUI/Module/Window/GUIWindowManager.h>
#include <Rudy/ImGui/Commands/ImGuiRenderCommands.h>
#include <Bite/Editor/Session/EditorSession.h>
#include <Bite/GUI/Painter/GUIPainter.h>
namespace Bite
{
	void WindowGUIModule::OnAttach()
	{
		/*
		* Create new window manager
		*/
		m_Manager = new GUIWindowManager(GetOwnerSession());

	}
	void WindowGUIModule::OnUpdate()
	{
		/*
		* Get current windows
		*/
		Rudy::Array<WindowLayout*> layouts = m_Manager->GetLayouts();
		Rudy::Array<WindowLayout*> finalizedWindows;

		/*
		* Draw windows
		*/
		Rudy::ImGuiRenderCommands* renderCommands = GetOwnerSession()->GetSessionPainter()->GetRenderCommands();
		for (unsigned int i = 0; i < layouts.GetCursor(); i++)
		{
			/*
			* Get layout
			*/
			WindowLayout* layout = layouts[i];

			/*
			* Initialize window state
			*/
			bool isExitRequested = false;
			bool isVisible = false;

			/*
			* Draw window
			*/
			isVisible = renderCommands->BeginWindow(layout->GetWindowName(),isExitRequested);

			/*
			* Check if window is visible
			*/
			if (isVisible && !isExitRequested)
			{
				/*
				* Set visibility invokes
				*/
				if (!layout->IsVisible())
				{
					layout->OnVisible();
				}

				/*
				* Render layout
				*/
				layout->OnLayoutRender();

				/*
				* Set visiblity state
				*/
				layout->SetVisibilityState(true);
			}
			else if (!isVisible && !isExitRequested)
			{
				if (layout->IsVisible())
				{
					layout->OnInvisible();
				}

				layout->SetVisibilityState(false);
			}
			else if (isExitRequested)
			{
				finalizedWindows.Add(layout);
			}

			renderCommands->FinalizeWindow();
		}

		/*
		* Remove finalized windows
		*/
		for (unsigned int i = 0; i < finalizedWindows.GetCursor(); i++)
		{
			m_Manager->RemoveWindow(finalizedWindows[i]);
		}
	}
	void WindowGUIModule::OnDetach()
	{
		delete m_Manager;
	}
}