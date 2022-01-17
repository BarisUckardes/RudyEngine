#pragma once
#include <Bite/GUI/Module/Window/WindowLayout.h>
#include <Bite/GUI/Module/Window/WindowLayoutGeneration.h>
#include <Rudy/Mathematics/Vector2f.h>
namespace Bite
{
	class DomainView;
	class DomainFolderView;
	class BITE_API DomainObserverGUIWindow : public WindowLayout
	{
	public:
		GENERATE_WINDOW(DomainObserverGUIWindow, "Domain Observer");
		GENERATE_REFLECTABLE_OBJECT(DomainObserverGUIWindow);

		DomainObserverGUIWindow() = default;
		~DomainObserverGUIWindow() = default;
	private:
		DomainView* m_DomainView;
		DomainFolderView* m_CurrentFolderView;
		Rudy::Vector2f m_FolderIconSize;
		Rudy::Vector2f m_FileIconSize;
		Rudy::Vector2f m_ItemPadding;
	};


}