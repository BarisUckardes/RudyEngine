#pragma once
#include <Bite/GUI/Module/Window/WindowLayout.h>
#include <Bite/GUI/Module/Window/WindowLayoutGeneration.h>
namespace Bite
{
	class BITE_API GUIWindowManager
	{
		friend class WindowGUIModule;
	public:
		static GUIWindowManager* Get();
	private:
		static GUIWindowManager* s_Manager;
	public:
		

		void RegisterWindow(Rudy::ReflectionType* type);
		void RemoveWindow();
		Rudy::Array<WindowLayout*> GetLayouts() const;
	private:
		GUIWindowManager(EditorSession* session);
		~GUIWindowManager();
		void SetupWindowGenerators();
	private:
		Rudy::Array<WindowLayoutGenerator> m_Generators;
		Rudy::Array<WindowLayout*> m_ActiveLayouts;
		EditorSession* m_Session;
	};


}