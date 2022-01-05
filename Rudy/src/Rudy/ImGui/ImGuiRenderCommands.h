#pragma once
#include <Rudy/Core/Symbols.h>
namespace Rudy
{
	class String;
	class RUDY_API ImGuiRenderCommands
	{
	public:
		ImGuiRenderCommands() = delete;
		~ImGuiRenderCommands() = delete;

		static void ShowDemoWindow();

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
		static bool BeginWindow(const String& name, bool& isExitRequested);

		/// <summary>
		/// Finalizes the rendering of a window
		/// </summary>
		static void FinalizeWindow();
	};


}