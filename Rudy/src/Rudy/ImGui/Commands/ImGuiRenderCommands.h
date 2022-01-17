#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/ImGui/Flags/GUIWindowFlags.h>
namespace Rudy
{
	class String;
	struct Vector2f;
	class RUDY_API ImGuiRenderCommands
	{
	public:
		ImGuiRenderCommands() = delete;
		~ImGuiRenderCommands() = delete;

		//static void ShowDemoWindow();

		/// <summary>
		/// Begins the rendering of the main menu bar
		/// </summary>
		static bool BeginMainMenuBar();

		/// <summary>
		/// Finalizes the rendering of the main menu bar
		/// </summary>
		static void FinalizeMainMenuBar();

		/// <summary>
		/// Begins the rendering of a menu
		/// </summary>
		/// <param name="name"></param>
		/// <returns></returns>
		static bool BeginMenu(const String& name);

		/// <summary>
		/// Finalizes the rendering of a menu
		/// </summary>
		static void FinalizeMenu();

		/// <summary>
		/// Begins the rendering of a menu item
		/// </summary>
		/// <param name="name"></param>
		/// <returns></returns>
		static bool CreateMenuItem(const String& name);

		/// <summary>
		/// Begins the rendering of a window
		/// </summary>
		/// <param name="name"></param>
		/// <param name="isExitRequested"></param>
		/// <returns></returns>
		static bool BeginWindow(const String& name, bool& isExitRequested,int flags = GUIWindowFlags::None);

		/// <summary>
		/// Begins the rendering of a window
		/// </summary>
		/// <param name="name"></param>
		/// <param name="isExitRequested"></param>
		/// <returns></returns>
		static bool BeginWindow(const String& name, int flags = GUIWindowFlags::None);

		/// <summary>
		/// Finalizes the rendering of a window
		/// </summary>
		static void FinalizeWindow();

		/// <summary>
		/// Creates a selectable item
		/// </summary>
		/// <param name="name"></param>
		/// <returns></returns>
		static bool CreateSelectableItem(const String& name);

		/// <summary>
		/// Creates a text label 
		/// </summary>
		/// <param name="text"></param>
		static void CreateText(const String& text);

		/// <summary>
		/// Creates an horizontal line
		/// </summary>
		static void CreateHorizontalLine();

		/// <summary>
		/// Creates an interactable button
		/// </summary>
		/// <param name="name"></param>
		/// <returns></returns>
		static bool CreateButton(const String& name);

		/// <summary>
		/// Creates and interactable button with a size parameter
		/// </summary>
		/// <param name="name"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		static bool CreateButton(const String& name, const Vector2f& size);
	};
}