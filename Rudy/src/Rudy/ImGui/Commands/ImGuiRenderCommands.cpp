#include "ImGuiRenderCommands.h"
#include <Rudy/Memory/String.h>
#include <IMGUI/imgui.h>
#include <Rudy/Mathematics/Vector2f.h>
#include <Rudy/Graphics/Texture/Texture2D.h>
#include <stdio.h>
#include <Rudy/Platform/Implementation/Graphics/OpenGL/ImGui/OpenGLImGuiRenderCommands.h>
namespace Rudy
{
	ImGuiRenderCommands* ImGuiRenderCommands::Create(GraphicsAPIType type)
	{
		switch (type)
		{
			case Rudy::GraphicsAPIType::Undefined:
				break;
			case Rudy::GraphicsAPIType::OpenGL:
				return new OpenGLImGuiRenderCommands();
				break;
			case Rudy::GraphicsAPIType::DÝrectx9:
				break;
			case Rudy::GraphicsAPIType::Directx11:
				break;
			case Rudy::GraphicsAPIType::Directx12:
				break;
			case Rudy::GraphicsAPIType::Directx13:
				break;
			case Rudy::GraphicsAPIType::Vulkan:
				break;
			default:
				break;
		}
	}
	bool ImGuiRenderCommands::BeginMainMenuBar() const
	{
		return ImGui::BeginMainMenuBar();
	}
	void ImGuiRenderCommands::FinalizeMainMenuBar() const
	{
		ImGui::EndMainMenuBar();
	}
	bool ImGuiRenderCommands::BeginMenu(const String& name) const
	{
		return ImGui::BeginMenu(*name);
	}
	void ImGuiRenderCommands::FinalizeMenu() const
	{
		ImGui::EndMenu();
	}
	bool ImGuiRenderCommands::CreateMenuItem(const String& name) const
	{
		return ImGui::MenuItem(*name);
	}
	bool ImGuiRenderCommands::BeginWindow(const String& name, bool& isExitRequested, GUIWindowFlags flags) const
	{
		bool exitRequest = true;
		bool state = ImGui::Begin(*name, &exitRequest,(int)flags); 
		isExitRequested = !exitRequest;
		return state;
	}
	bool ImGuiRenderCommands::BeginWindow(const String& name, GUIWindowFlags flags) const
	{
		bool state = ImGui::Begin(*name,nullptr,(int)flags);
		return state;
	}

	void ImGuiRenderCommands::FinalizeWindow() const
	{
		ImGui::End();
	}

	bool ImGuiRenderCommands::CreateSelectableItem(const String& name) const
	{
		return ImGui::Selectable(*name);
	}

	void ImGuiRenderCommands::CreateText(const String& text) const
	{
		ImGui::Text(*text);
	}

	void ImGuiRenderCommands::CreateHorizontalLine() const
	{
		ImGui::Separator();
	}

	bool ImGuiRenderCommands::CreateButton(const String& name) const
	{
		return ImGui::Button(*name);
	}

	bool ImGuiRenderCommands::CreateButton(const String& name, const Vector2f& size) const
	{
		return ImGui::Button(*name,ImVec2(size.X,size.Y));
	}

	float ImGuiRenderCommands::CreateFloatSlider(const String& name,float value,float min,float max) const
	{
		float intermediateValue = value;
		ImGui::SliderFloat(*name,&intermediateValue,min,max);
		return intermediateValue;
	}

	Vector2f ImGuiRenderCommands::CreateVector2Slider(const String& name, const Vector2f& value, float min, float max) const
	{
		Vector2f intermediateValue = value;
		ImGui::SliderFloat2(*name, &intermediateValue.X, min, max);
		return intermediateValue;
	}

	void ImGuiRenderCommands::SignalPopup(const String& name) const
	{
		ImGui::OpenPopup(*name);
	}

	bool ImGuiRenderCommands::BeginPopup(const String& popupName,GUIWindowFlags flags) const
	{
		return ImGui::BeginPopup(*popupName,(int)flags);
	}

	void ImGuiRenderCommands::FinalizePopup() const
	{
		ImGui::EndPopup();
	}

	void ImGuiRenderCommands::TerminateCurrentPopup() const
	{
		ImGui::CloseCurrentPopup();
	}

	void ImGuiRenderCommands::CreateImage(Texture2D* texture, const Vector2f& size) const
	{
		int texID = *(int*)texture->GetNativeHandle();
		ImGui::Image((int*)texID, ImVec2(size.X,size.Y));
	}
	
}