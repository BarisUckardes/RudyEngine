#include "BiteModule.h"
#include <Rudy/ImGui/ImGuiRenderer.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Windowing/Window.h>
#include <Rudy/ImGui/ImGuiRenderCommands.h>
#include <Bite/GUI/Module/GUIModule.h>
#include <Bite/Editor/Session/EditorSession.h>
namespace Bite
{
	BiteModule::BiteModule(const Rudy::Array<GUIModule*>& guiModules)
	{
		m_PendingGUIModules = guiModules;
	}
	void BiteModule::OnAttach()
	{
		/*
		* Get default graphics device
		*/
		Rudy::GraphicsDevice* defaultDevice = GetOwnerSession()->GetDefaultGraphicsDevice();

		/*
		* Create imgui renderer
		*/
		m_ImGuiRenderer = new Rudy::ImGuiRenderer(defaultDevice->GetTargetWindow()->GetSize(), defaultDevice->GetApiType());

		/*
		* Create editor session
		*/
		EditorSession* editorSession = new EditorSession(GetOwnerSession());
		m_Session = editorSession;

		/*
		* Attach gui modules
		*/
		for (int i = 0; i < m_PendingGUIModules.GetCursor(); i++)
		{
			/*
			* Get GUI module
			*/
			GUIModule* guiModule = m_PendingGUIModules[i];

			/*
			* Set owner session for the gui module
			*/
			guiModule->SetOwnerSession(editorSession);

			/*
			* Attach module
			*/
			guiModule->OnAttach();

			/*
			* Register to the active modules
			*/
			m_GUIModules.Add(guiModule);
		}
		m_PendingGUIModules.Clear();

	}
	void BiteModule::OnUpdate()
	{
		/*
		* Start bite gui modules
		*/
		m_ImGuiRenderer->Begin();

		/*
		* Update each gui module
		*/
		for (int i = 0; i < m_GUIModules.GetCursor(); i++)
		{
			/*
			* Get gui module
			*/
			GUIModule* guiModule = m_GUIModules[i];

			/*
			* Update module
			*/
			guiModule->OnUpdate();
		}
		Rudy::ImGuiRenderCommands::ShowDemoWindow();

		/*
		* End bite gui modules
		*/
		m_ImGuiRenderer->End();
	}
	void BiteModule::OnDetach()
	{
		/*
		* Attach gui modules
		*/
		for (int i = 0; i < m_GUIModules.GetCursor(); i++)
		{
			/*
			* Get GUI module
			*/
			GUIModule* guiModule = m_GUIModules[i];

			/*
			* Attach module
			*/
			guiModule->OnDetach();

			/*
			* Register to the active modules
			*/
			m_GUIModules.Remove(guiModule);
		}
		m_GUIModules.Clear();

		/*
		* Delete editor session
		*/
	}
	void BiteModule::OnReceiveApplicationEvent(Rudy::Event* event)
	{
		m_ImGuiRenderer->OnEventReceived(event);
	}
}