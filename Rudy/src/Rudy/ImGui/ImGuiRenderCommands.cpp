#include "ImGuiRenderCommands.h"
#include <IMGUI/imgui.h>
namespace Rudy
{
	void ImGuiRenderCommands::ShowDemoWindow()
	{
		ImGui::ShowDemoWindow();
	}
	bool ImGuiRenderCommands::BeginMainMenuBar()
	{
		return ImGui::BeginMainMenuBar();
	}
	void ImGuiRenderCommands::FinalizeMainMenuBar()
	{
		ImGui::EndMainMenuBar();
	}
}