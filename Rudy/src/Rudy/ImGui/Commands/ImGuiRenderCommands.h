#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/ImGui/Flags/GUIWindowFlags.h>
#include <Rudy/ImGui/Flags/GUIDockNodeFlags.h>
#include <Rudy/Platform/Implementation/Graphics/GraphicsAPIType.h>
namespace Rudy
{
	class String ;
	class Texture2D ;
	struct Vector2f ;
	struct Vector2i;
	class RUDY_API ImGuiRenderCommands
	{
	public:
		static ImGuiRenderCommands* Create(GraphicsAPIType preferredApiType);
		ImGuiRenderCommands() = default ;
		~ImGuiRenderCommands() = default ;


		/// <summary>
		/// Begins the rendering of the main menu bar
		/// </summary>
		bool BeginMainMenuBar()const ;

		/// <summary>
		/// Finalizes the rendering of the main menu bar
		/// </summary>
		void FinalizeMainMenuBar()const ;

		/// <summary>
		/// Begins the rendering of a menu
		/// </summary>
		/// <param name="name"></param>
		/// <returns></returns>
		bool BeginMenu(const String& name)const ;

		/// <summary>
		/// Finalizes the rendering of a menu
		/// </summary>
		void FinalizeMenu()const ;

		/// <summary>
		/// Begins the rendering of a menu item
		/// </summary>
		/// <param name="name"></param>
		/// <returns></returns>
		bool CreateMenuItem(const String& name)const ;

		/// <summary>
		/// Begins the rendering of a window
		/// </summary>
		/// <param name="name"></param>
		/// <param name="isExitRequested"></param>
		/// <returns></returns>
		bool BeginWindow(const String& name, bool& isExitRequested, GUIWindowFlags flags = GUIWindowFlags::None)const ;

		/// <summary>
		/// Begins the rendering of a window
		/// </summary>
		/// <param name="name"></param>
		/// <param name="isExitRequested"></param>
		/// <returns></returns>
		bool BeginWindow(const String& name, GUIWindowFlags flags = GUIWindowFlags::None)const ;

		/// <summary>
		/// Finalizes the rendering of a window
		/// </summary>
		void FinalizeWindow()const ;

		/// <summary>
		/// Creates a selectable item
		/// </summary>
		/// <param name="name"></param>
		/// <returns></returns>
		bool CreateSelectableItem(const String& name)const ;

		/// <summary>
		/// Creates a text label 
		/// </summary>
		/// <param name="text"></param>
		void CreateText(const String& text)const ;

		/// <summary>
		/// Creates an horizontal line
		/// </summary>
		void CreateHorizontalLine()const ;

		/// <summary>
		/// Creates an interactable button
		/// </summary>
		/// <param name="name"></param>
		/// <returns></returns>
		bool CreateButton(const String& name)const ;

		/// <summary>
		/// Creates an interactable textured button
		/// </summary>
		/// <param name="name"></param>
		/// <param name="texture"></param>
		/// <returns></returns>
		virtual bool CreateTexturedButton(const String& name, const Vector2f& size, const Texture2D* texture) const = 0;

		/// <summary>
		/// Creates and interactable button with a size parameter
		/// </summary>
		/// <param name="name"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		bool CreateButton(const String& name, const Vector2f& size)const ;

		/// <summary>
		/// Creates an float slider
		/// </summary>
		/// <returns></returns>
		float CreateFloatSlider(const String& name, float value, float min = 0.0f, float max = 100.0f)const ;

		/// <summary>
		/// Creates an vector2f slsider
		/// </summary>
		/// <param name="name"></param>
		/// <param name="value"></param>
		/// <param name="min"></param>
		/// <param name="max"></param>
		/// <returns></returns>
		Vector2f CreateVector2Slider(const String& name, const Vector2f& value, float min = 0.0f, float max = 100.0f)const ;

		/// <summary>
		/// Signals a popup to render
		/// </summary>
		/// <param name="name"></param>
		void SignalPopup(const String& name)const ;

		/// <summary>
		/// Begins the rendering of the popup
		/// </summary>
		bool BeginPopup(const String& popupName,GUIWindowFlags flags = GUIWindowFlags::None)const ;

		/// <summary>
		/// Finalizes the rendering of the popup
		/// </summary>
		void FinalizePopup()const ;

		/// <summary>
		/// Terminates the rendering of the popup
		/// </summary>
		void TerminateCurrentPopup()const ;

		/// <summary>
		/// Creates a texture box
		/// </summary>
		/// <param name="texture"></param>
		void CreateImage(Texture2D* texture,const Vector2f& size) const ;

		/// <summary>
		/// Creates a dockspace
		/// </summary>
		/// <param name="dockSpaceID"></param>
		/// <param name="position"></param>
		/// <param name="flags"></param>
		void CreateDockspace(const String& dockSpaceName, const Vector2i& position, GUIDockNodeFlags flags);
	};
}