#pragma once
#include <Bite/GUI/Module/GUIModule.h>

namespace Bite
{
	class GUIWindowManager;

	/// <summary>
	/// GUIModule for windowing
	/// </summary>
	class BITE_API WindowGUIModule : public GUIModule
	{
	public:
		WindowGUIModule() = default;
		~WindowGUIModule() = default;

	private:
		GUIWindowManager* m_Manager;

		// Inherited via GUIModule
		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnDetach() override;
	};


}