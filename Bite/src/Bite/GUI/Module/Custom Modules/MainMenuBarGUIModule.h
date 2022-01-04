#pragma once
#include <Bite/GUI/Module/GUIModule.h>

namespace Bite
{
	/// <summary>
	/// Handles the maisd
	/// </summary>
	class BITE_API MainMenuBarGUIModule : public GUIModule
	{
	public:
		MainMenuBarGUIModule() = default;
		~MainMenuBarGUIModule() = default;

		// Inherited via GUIModule
		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnDetach() override;
	};

}
