#include "GUIWindowManager.h"

namespace Bite
{
	GUIWindowManager* GUIWindowManager::s_Manager = nullptr;

	GUIWindowManager::GUIWindowManager(EditorSession* session)
	{
		s_Manager = this;
		m_Session = session;
		SetupWindowGenerators();
	}
	GUIWindowManager::~GUIWindowManager()
	{
		m_Session = nullptr;

		/*
		* Delete all window layouts
		*/

	}
	GUIWindowManager* GUIWindowManager::Get()
	{
		return s_Manager;
	}
	void GUIWindowManager::RegisterWindow(Rudy::ReflectionType* type)
	{
		/*
		* Iterate and validate
		*/
		for (int i = 0; i < m_Generators.GetCursor(); i++)
		{
			/*
			* Get generated layout
			*/
			WindowLayout* layout = m_Generators[i]();

			/*
			* Validate
			*/
			if (layout->GetType() == type)
			{
				/*
				* Set editor session
				*/
				layout->SetEditorSession(m_Session);

				/*
				* Call setp
				*/
				layout->OnLayoutSetup();

				/*
				* Register
				*/
				m_ActiveLayouts.Add(layout);
				return;
			}

			delete layout;
		}
	}

	void GUIWindowManager::RemoveWindow(WindowLayout* layout)
	{
		/*
		* Iterate and validates
		*/
		for (int i = 0; i < m_ActiveLayouts.GetCursor(); i++)
		{
			/*
			* Get layout
			*/
			WindowLayout* windowLayout = m_ActiveLayouts[i];

			/*
			* Validate
			*/
			if (windowLayout == layout)
			{
				windowLayout->OnLayoutFinalize();
				delete windowLayout;
				m_ActiveLayouts.RemoveIndex(i);
				return;
			}
		}
	}
	Rudy::Array<WindowLayout*> GUIWindowManager::GetLayouts() const
	{
		return m_ActiveLayouts;
	}
	void GUIWindowManager::SetupWindowGenerators()
	{
		m_Generators = WindowLayoutGeneratorRegistry::GetCurrent().GetGenerators();
	}
}