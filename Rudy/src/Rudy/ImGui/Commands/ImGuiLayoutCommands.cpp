#include "ImGuiLayoutCommands.h"
#include <IMGUI/imgui.h>
#include <Rudy/Mathematics/Vector2f.h>
namespace Rudy
{
	void ImGuiLayoutCommands::StayHere()
	{
		ImGui::SameLine();
	}
	void ImGuiLayoutCommands::SetCursorPosition(const Vector2f& position)
	{
		ImGui::SetCursorPos(ImVec2(position.X, position.Y));
	}
	void ImGuiLayoutCommands::SetNextWindowSize(const Vector2f& size)
	{
		ImGui::SetNextWindowSize(ImVec2(size.X, size.Y));
	}
	void ImGuiLayoutCommands::SetNextWindowPosition(const Vector2f& position)
	{
		ImGui::SetNextWindowPos(ImVec2(position.X, position.Y));
	}
	void ImGuiLayoutCommands::SetCurrentWindowFontScale(float scale)
	{
		ImGui::SetWindowFontScale(scale);
	}
	Vector2f ImGuiLayoutCommands::GetViewportSize()
	{
		return Vector2f(ImGui::GetMainViewport()->Size.x, ImGui::GetMainViewport()->Size.y);
	}
	Vector2f ImGuiLayoutCommands::GetViewportPosition()
	{
		return Vector2f(ImGui::GetMainViewport()->Pos.x, ImGui::GetMainViewport()->Pos.y);
	}
	Vector2f ImGuiLayoutCommands::GetAvailableSpace()
	{
		return Vector2f(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y);
	}
	Vector2f ImGuiLayoutCommands::GetCursorPosition()
	{
		return Vector2f(ImGui::GetCursorPos().x, ImGui::GetCursorPos().y);
	}
}