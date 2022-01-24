#include "ImGuiRenderCommands.h"
#include <Rudy/Memory/String.h>
#include <IMGUI/imgui.h>
#include <Rudy/Mathematics/Vector2f.h>
#include <Rudy/Graphics/Texture/Texture2D.h>
#include <stdio.h>
namespace Rudy
{
	//void ImGuiRenderCommands::ShowDemoWindow()
	//{
	//	ImGui::ShowDemoWindow();
	//}
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
	bool ImGuiRenderCommands::BeginWindow(const String& name, bool& isExitRequested, GUIWindowFlags flags)
	{
		bool exitRequest = true;
		bool state = ImGui::Begin(*name, &exitRequest,(int)flags);
		isExitRequested = !exitRequest;
		return state;
	}
	bool ImGuiRenderCommands::BeginWindow(const String& name, GUIWindowFlags flags)
	{
		bool state = ImGui::Begin(*name,nullptr,(int)flags);
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

	bool ImGuiRenderCommands::CreateTexturedButton(const String& name,const Vector2f& size, const Texture2D* texture)
	{
		int texID = *(int*)texture->GetNativeHandle();
		ImGui::PushID(*name);
		bool state = ImGui::ImageButton((int*)texID, ImVec2(size.X, size.Y));
		ImGui::PopID();
		return state;
	}

	bool ImGuiRenderCommands::CreateTexturedButton(const Vector2f& size, int tex)
	{
		return ImGui::ImageButton((int*)tex, ImVec2(size.X, size.Y));
	}

	bool ImGuiRenderCommands::CreateButton(const String& name, const Vector2f& size)
	{
		return ImGui::Button(*name,ImVec2(size.X,size.Y));
	}

	float ImGuiRenderCommands::CreateFloatSlider(const String& name,float value,float min,float max)
	{
		float intermediateValue = value;
		ImGui::SliderFloat(*name,&intermediateValue,min,max);
		return intermediateValue;
	}

	Vector2f ImGuiRenderCommands::CreateVector2Slider(const String& name, const Vector2f& value, float min, float max)
	{
		Vector2f intermediateValue = value;
		ImGui::SliderFloat2(*name, &intermediateValue.X, min, max);
		return intermediateValue;
	}

	void ImGuiRenderCommands::SignalPopup(const String& name)
	{
		ImGui::OpenPopup(*name);
	}

	bool ImGuiRenderCommands::BeginPopup(const String& popupName,GUIWindowFlags flags)
	{
		return ImGui::BeginPopup(*popupName,(int)flags);
	}

	void ImGuiRenderCommands::FinalizePopup()
	{
		ImGui::EndPopup();
	}

	void ImGuiRenderCommands::TerminateCurrentPopup()
	{
		ImGui::CloseCurrentPopup();
	}

	void ImGuiRenderCommands::CreateImage(Texture2D* texture, const Vector2f& size)
	{
		int texID = *(int*)texture->GetNativeHandle();
		ImGui::Image((int*)texID, ImVec2(size.X,size.Y));
	}
	
}