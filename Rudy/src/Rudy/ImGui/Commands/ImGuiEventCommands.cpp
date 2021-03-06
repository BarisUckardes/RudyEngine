#include "ImGuiEventCommands.h"
#include <IMGUI/imgui.h>

namespace Rudy
{
    bool ImGuiEventCommands::IsKeyPressed(unsigned int key)
    {
        return ImGui::IsKeyPressed(key);
    }
    bool ImGuiEventCommands::IsKeyDown(unsigned int key)
    {
        return ImGui::IsKeyDown(key);
    }
    bool ImGuiEventCommands::IsKeyReleased(unsigned int key)
    {
        return ImGui::IsKeyReleased(key);
    }
    bool ImGuiEventCommands::IsCurrentItemClicked()
    {
        return ImGui::IsItemClicked();
    }
    bool ImGuiEventCommands::IsMouseButtonClicked(GUIMouseButtons button)
    {
        return ImGui::IsMouseClicked((int)button);
    }
    bool ImGuiEventCommands::IsMouseButtonDoubleClicked(GUIMouseButtons button)
    {
        return ImGui::IsMouseDoubleClicked((int)button);
    }
    bool ImGuiEventCommands::IsMouseButtonDown(GUIMouseButtons button)
    {
        return ImGui::IsMouseDown((int)button);
    }
    bool ImGuiEventCommands::IsMouseButtonReleased(GUIMouseButtons button)
    {
        return ImGui::IsMouseReleased((int)button);
    }
    bool ImGuiEventCommands::IsCurrentItemHavored()
    {
        return ImGui::IsItemHovered();
    }
    bool ImGuiEventCommands::IsAnyItemHavored()
    {
        return ImGui::IsAnyItemHovered();
    }
    bool ImGuiEventCommands::IsWindowFocused()
    {
        return ImGui::IsWindowFocused();
    }
    bool ImGuiEventCommands::IsWindowHavored()
    {
        return ImGui::IsWindowHovered();
    }
}