#pragma once
#include <Bite/GUI/Module/Window/WindowLayout.h>
#include <Bite/GUI/Module/Window/WindowLayoutGeneration.h>
namespace Bite
{
	class BITE_API WorldObserverGUIWindow : public WindowLayout
	{
	public:
		GENERATE_WINDOW(WorldObserverGUIWindow, "World Observer");
		GENERATE_REFLECTABLE_OBJECT(WorldObserverGUIWindow);
		WorldObserverGUIWindow() = default;
		~WorldObserverGUIWindow() = default;
	};


}