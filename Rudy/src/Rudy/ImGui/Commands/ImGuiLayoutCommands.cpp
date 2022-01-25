#include "ImGuiLayoutCommands.h"
#include <IMGUI/imgui.h>
#include <Rudy/Mathematics/Vector2f.h>
namespace Rudy
{
	void ImGuiLayoutCommands::StayHere() const
	{
		ImGui::SameLine();
	}
	void ImGuiLayoutCommands::SetCursorPosition(const Vector2f& position) const
	{
		ImGui::SetCursorPos(ImVec2(position.X, position.Y));
	}
	void ImGuiLayoutCommands::SetNextWindowSize(const Vector2f& size) const
	{
		ImGui::SetNextWindowSize(ImVec2(size.X, size.Y));
	}
	void ImGuiLayoutCommands::SetNextWindowPosition(const Vector2f& position) const
	{
		ImGui::SetNextWindowPos(ImVec2(position.X, position.Y));
	}
	void ImGuiLayoutCommands::SetCurrentWindowFontScale(float scale) const
	{
		ImGui::SetWindowFontScale(scale);
	}
	Vector2f ImGuiLayoutCommands::GetViewportSize() const
	{
		return Vector2f(ImGui::GetMainViewport()->Size.x, ImGui::GetMainViewport()->Size.y);
	}
	Vector2f ImGuiLayoutCommands::GetViewportPosition() const
	{
		return Vector2f(ImGui::GetMainViewport()->Pos.x, ImGui::GetMainViewport()->Pos.y);
	}
	Vector2f ImGuiLayoutCommands::GetAvailableSpace() const
	{
		return Vector2f(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y);
	}
	Vector2f ImGuiLayoutCommands::GetCursorPosition() const
	{
		return Vector2f(ImGui::GetCursorPos().x, ImGui::GetCursorPos().y);
	}
}