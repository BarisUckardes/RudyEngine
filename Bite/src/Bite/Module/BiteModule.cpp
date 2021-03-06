#include "BiteModule.h"
#include <Rudy/ImGui/ImGuiRenderer.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Platform/Window/PlatformWindow.h>
#include <Bite/GUI/Module/GUIModule.h>
#include <Bite/Editor/Session/EditorSession.h>
#include <Bite/Editor/Command/EditorCommand.h>
#include <Rudy/ImGui/Commands/ImGuiRenderCommands.h>
#include <Rudy/ImGui/Commands/ImGuiLayoutCommands.h>
#include <Bite/GUI/Painter/GUIPainter.h>
namespace Bite
{
	BiteModule::BiteModule(const Rudy::Array<GUIModule*>& guiModules,const Rudy::Array<EditorCommand*>& editorCommands)
	{
		m_PendingGUIModules = guiModules;
		m_EditorCommands = editorCommands;
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
		m_ImGuiRenderer = new Rudy::ImGuiRenderer(
			defaultDevice->GetTargetWindow()->GetSize(),
			defaultDevice->GetApiType(),
			Rudy::GUIBackendFlags::None, Rudy::GUIConfigFlags::DockingEnable);

		/*
		* Create gui painter
		*/
		GUIPainter* painter = new GUIPainter(defaultDevice->GetApiType());
		m_Painter = painter;

		/*
		* Create editor session
		*/
		EditorSession* editorSession = new EditorSession(GetOwnerSession(),painter);
		m_Session = editorSession;

		/*
		* Execute editor commands
		*/
		for (int i = 0; i < m_EditorCommands.GetCursor(); i++)
		{
			/*
			* Get editor command
			*/
			EditorCommand* editorCommand = m_EditorCommands[i];

			/*
			* Set owner session
			*/
			editorCommand->SetOwnerSession(editorSession);

			/*
			* Call initialize method
			*/
			editorCommand->OnInitialize();
		}

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
		* Create dockspace window
		*/
		m_Painter->GetLayoutCommands()->SetNextWindowPosition(m_Painter->GetLayoutCommands()->GetViewportPosition());
		m_Painter->GetLayoutCommands()->SetNextWindowSize(m_Painter->GetLayoutCommands()->GetViewportSize());
		m_Painter->GetRenderCommands()->BeginWindow("DockspaceWindow",
			Rudy::GUIWindowFlags::NoTitleBar | Rudy::GUIWindowFlags::NoCollapse | Rudy::GUIWindowFlags::NoResize | Rudy::GUIWindowFlags::NoMove |
			Rudy::GUIWindowFlags::NoBringToFrontOnFocus | Rudy::GUIWindowFlags::NoNavFocus | Rudy::GUIWindowFlags::MenuBar);

		/*
		* Create dockspace
		*/
		m_Painter->GetRenderCommands()->CreateDockspace("MainDockspace", Rudy::Vector2i(0, 0),Rudy::GUIDockNodeFlags::None | Rudy::GUIDockNodeFlags::PassthruCentralNode);

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

		/*
		* End dockspace window
		*/
		m_Painter->GetRenderCommands()->FinalizeWindow();

		/*
		* End bite gui modules
		*/
		m_ImGuiRenderer->End();
		m_Painter->ClearEvents();
	}
	void BiteModule::OnDetach()
	{
		
		/*
		* Execute editor commands
		*/
		for (int i = 0; i < m_EditorCommands.GetCursor(); i++)
		{
			/*
			* Get editor command
			*/
			EditorCommand* editorCommand = m_EditorCommands[i];

			/*
			* Call initialize method
			*/
			editorCommand->OnFinalize();
		}
		return;
		/*
		* Detach gui modules
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
		delete m_Session;
		m_Session = nullptr;
	}
	void BiteModule::OnReceiveApplicationEvent(Rudy::Event* event)
	{
		/*
		* Forward events to imgui renderer
		*/
		m_ImGuiRenderer->OnEventReceived(event);

		/*
		* Forward events to gui painter
		*/
		m_Painter->OnPainterReceivedEvent(event);
	}
}