#include "ImGuiRenderCommands.h"
#include <Rudy/Memory/String.h>
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
	bool ImGuiRenderCommands::BeginMenu(const String& name)
	{
		return ImGui::BeginMenu(*name);
	}
	void ImGuiRenderCommands::FinalizeMenu()
	{
		ImGui::EndMenu();
	}
	bool ImGuiRenderCommands::CreateMenuItem(const String& name)
	{
		return ImGui::MenuItem(*name);
	}
}