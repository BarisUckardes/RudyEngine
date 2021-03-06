#pragma once
#include <Bite/GUI/Module/Window/WindowLayout.h>
#include <Bite/GUI/Module/Window/WindowLayoutGeneration.h>
#include <Rudy/Mathematics/Vector2f.h>
namespace Rudy
{
	class Texture2D;
}
namespace Bite
{
	class DomainView;
	class DomainFolderView;
	class DomainAssetView;
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
		DomainFolderView* m_CurrentQuickMenuFolderView;
		DomainAssetView* m_CurrentQuickMenuAssetView;

		Rudy::Texture2D* m_FolderIconTexture;
		Rudy::Texture2D* m_FolderRenameTexture;
		Rudy::Texture2D* m_FolderDeleteTexture;

		Rudy::Texture2D* m_AssetRenameTexture;
		Rudy::Texture2D* m_AssetDeleteTexture;

		Rudy::Vector2f m_FolderIconSize;
		Rudy::Vector2f m_AssetIconSize;
		Rudy::Vector2f m_ItemPadding;
		float m_ItemTextSize;
	};


}