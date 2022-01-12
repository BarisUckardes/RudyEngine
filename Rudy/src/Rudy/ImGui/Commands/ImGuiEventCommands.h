#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/ImGui/Flags/GUIMouseButtons.h>

namespace Rudy
{
	/// <summary>
	/// Commands specialized in events and states
	/// </summary>
	class RUDY_API ImGuiEventCommands
	{
	public:
		ImGuiEventCommands() = delete;
		~ImGuiEventCommands() = delete;


		/// <summary>
		/// Returns whether the target key is pressed
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		static bool IsKeyPressed(unsigned int key);

		/// <summary>
		/// Returns whether the target key is currently held down
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		static bool IsKeyDown(unsigned int key);

		/// <summary>
		/// Returns whether the target key is released
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		static bool IsKeyReleased(unsigned int key);

		/// <summary>
		/// Returns whether the current item is clicked
		/// </summary>
		/// <returns></returns>
		static bool IsCurrentItemClicked();

		/// <summary>
		/// Returns whether the target mouse button item is  clicked
		/// </summary>
		/// <returns></returns>
		static bool IsMouseButtonClicked(GUIMouseButtons button);

		/// <summary>
		/// Returns whether the target mouse button is double clicked
		/// </summary>
		/// <returns></returns>
		static bool IsMouseButtonDoubleClicked(GUIMouseButtons button);

		/// <summary>
		/// Returns whether the target mouse buttons is currently held down
		/// </summary>
		/// <param name="button"></param>
		/// <returns></returns>
		static bool IsMouseButtonDown(GUIMouseButtons button);

		/// <summary>
		/// Returns whether the targer mouse button is released
		/// </summary>
		/// <param name="button"></param>
		/// <returns></returns>
		static bool IsMouseButtonReleased(GUIMouseButtons button);

        /// <summary>
        /// Returns if current item is havored
        /// </summary>
        /// <returns></returns>
        static bool IsCurrentItemHavored();

        /// <summary>
        /// Returns if an any item is havored
        /// </summary>
        /// <returns></returns>
        static bool IsAnyItemHavored();

        /// <summary>
        /// Returns if the window is focused
        /// </summary>
        /// <returns></returns>
        static bool IsWindowFocused();

        /// <summary>
        /// Returns if the window is havored
        /// </summary>
        /// <returns></returns>
        static bool IsWindowHavored();
	};


}