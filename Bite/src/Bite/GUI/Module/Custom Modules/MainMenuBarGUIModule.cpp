#include "MainMenuBarGUIModule.h"
#include <Rudy/ImGui/ImGuiRenderCommands.h>
namespace Bite
{
	void MainMenuBarGUIModule::OnAttach()
	{
	}

	void MainMenuBarGUIModule::OnUpdate()
	{
		if (Rudy::ImGuiRenderCommands::BeginMainMenuBar())
		{
			Rudy::ImGuiRenderCommands::FinalizeMainMenuBar();
		}
	}

	void MainMenuBarGUIModule::OnDetach()
	{
		
	}
}
