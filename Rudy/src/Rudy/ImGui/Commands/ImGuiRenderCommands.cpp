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
	bool ImGuiRenderCommands::BeginWindow(const String& name, bool& isExitRequested, int flags)
	{
		bool exitRequest = true;
		bool state = ImGui::Begin(*name, &exitRequest,flags);
		isExitRequested = !exitRequest;
		return state;
	}
	bool ImGuiRenderCommands::BeginWindow(const String& name, int flags)
	{
		bool state = ImGui::Begin(*name,nullptr,flags);
		return state;
	}

	void ImGuiRenderCommands::FinalizeWindow()
	{
		ImGui::End();
	}

	bool ImGuiRenderCommands::CreateSelectableItem(const String& name)
	{
		return ImGui::Selectable(*name);
	}

	void ImGuiRenderCommands::CreateText(const String& text)
	{
		ImGui::Text(*text);
	}

	void ImGuiRenderCommands::CreateHorizontalLine()
	{
		ImGui::Separator();
	}

	bool ImGuiRenderCommands::CreateButton(const String& name)
	{
		return ImGui::Button(*name);
	}
	
}