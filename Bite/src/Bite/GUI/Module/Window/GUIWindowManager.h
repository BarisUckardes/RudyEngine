#pragma once
#include <Bite/GUI/Module/Window/WindowLayout.h>
#include <Bite/GUI/Module/Window/WindowLayoutGeneration.h>
namespace Bite
{
	/// <summary>
	/// GUIWindow manager class for creating and destroying
	/// </summary>
	class BITE_API GUIWindowManager
	{
		friend class WindowGUIModule;
	public:
		/// <summary>
		/// Returns the global instance of the gui manager
		/// </summary>
		/// <returns></returns>
		static GUIWindowManager* Get();
	private:
		static GUIWindowManager* s_Manager;
	public:
		/// <summary>
		/// Registers&Creates new window with the specified type
		/// </summary>
		/// <param name="type"></param>
		void RegisterWindow(Rudy::ReflectionType* type);

		/// <summary>
		/// Deletes the existing window
		/// </summary>
		/// <param name="layout"></param>
		void RemoveWindow(WindowLayout* layout);

		/// <summary>
		/// Returns the current window layouts
		/// </summary>
		/// <returns></returns>
		Rudy::Array<WindowLayout*> GetLayouts() const;
	private:
		GUIWindowManager(EditorSession* session);
		~GUIWindowManager();

		/// <summary>
		/// Loads and caches window layout generators
		/// </summary>
		void SetupWindowGenerators();
	private:
		Rudy::Array<WindowLayoutGenerator> m_Generators;
		Rudy::Array<WindowLayout*> m_ActiveLayouts;
		EditorSession* m_Session;
	};


}