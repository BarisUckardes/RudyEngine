#pragma once
#include <Rudy/Core/Symbols.h>
namespace Rudy
{
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
	};


}