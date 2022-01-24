#include "DomainObserverGUIWindow.h"
#include <Rudy/ImGui/Commands/ImGuiCommands.h>
#include <Bite/Editor/Session/EditorSession.h>
#include <Bite/Domain/DomainView.h>
#include <Bite/Domain/DomainFolderView.h>
#include <Bite/Domain/DomainAssetView.h>
#include <Rudy/Graphics/Texture/Texture2D.h>
#include <stdio.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
namespace Bite
{
	GENERATE_REFLECTABLE_TYPE(DomainObserverGUIWindow);
	GENERATE_WINDOW_GENERATOR(DomainObserverGUIWindow);

	#define DEFAULT_ITEM_PADDING_HORIZONTAL 8
	#define DEFAULT_ITEM_PADDING_VERTICAL 8
	#define DEFAULT_FOLDER_ICON_SIZE 64
	#define DEFAULT_ASSET_ICON_SIZE 48
	#define DEFAULT_ITEM_TEXT_SIZE 16
	#define DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE 16
	
	void DomainObserverGUIWindow::OnLayoutSetup()
	{
		/*
		* Get domain view
		*/
		m_DomainView = GetOwnerSession()->GetDomainView();

		/*
		* Set current folder view
		*/
		m_CurrentFolderView = m_DomainView->GetRootFolder();

		/*
		* Set default properties
		*/
		m_AssetIconSize = Rudy::Vector2f(DEFAULT_ASSET_ICON_SIZE, DEFAULT_ASSET_ICON_SIZE);
		m_FolderIconSize = Rudy::Vector2f(DEFAULT_FOLDER_ICON_SIZE, DEFAULT_FOLDER_ICON_SIZE);
		m_ItemPadding = Rudy::Vector2f(DEFAULT_ITEM_PADDING_HORIZONTAL, DEFAULT_ITEM_PADDING_VERTICAL);
		m_ItemTextSize = DEFAULT_ITEM_TEXT_SIZE;

		/*
		* Get editor resources
		*/
		m_FolderIconTexture = (Rudy::Texture2D*)GetOwnerSession()->GetEditorResource(Rudy::AssetType::Texture2D, "FolderIcon.png");
		m_FolderDeleteTexture = (Rudy::Texture2D*)GetOwnerSession()->GetEditorResource(Rudy::AssetType::Texture2D, "DeleteIcon.png");
		m_FolderRenameTexture = (Rudy::Texture2D*)GetOwnerSession()->GetEditorResource(Rudy::AssetType::Texture2D, "EditIcon.png");
		m_AssetDeleteTexture = (Rudy::Texture2D*)GetOwnerSession()->GetEditorResource(Rudy::AssetType::Texture2D, "DeleteIcon.png");
		m_AssetRenameTexture = (Rudy::Texture2D*)GetOwnerSession()->GetEditorResource(Rudy::AssetType::Texture2D, "EditIcon.png");
	}
	void DomainObserverGUIWindow::OnLayoutRender()
	{
		/*
		* Next frame properties
		*/
		DomainFolderView* nextFrameFolderView = m_CurrentFolderView;
		DomainFolderView* nextFrameQuickFolderView = m_CurrentQuickMenuFolderView;
		DomainAssetView* nextFrameQuickAssetView = m_CurrentQuickMenuAssetView;

		/*
		* Render current folder path
		*/
		if (m_CurrentFolderView->GetParentFolder() != nullptr && Rudy::ImGuiRenderCommands::CreateButton("Back"))
		{
			nextFrameFolderView = m_CurrentFolderView->GetParentFolder();
		}
		Rudy::ImGuiLayoutCommands::StayHere();
		Rudy::ImGuiRenderCommands::CreateText(m_CurrentFolderView->GetAbsolutePath());
		Rudy::ImGuiRenderCommands::CreateHorizontalLine();

		/*
		* Render folders
		*/
		Rudy::Array<DomainFolderView*> subFolders = m_CurrentFolderView->GetSubFolders();
		const Rudy::Vector2f itemAvailableSpace = Rudy::ImGuiLayoutCommands::GetAvailableSpace();
		const Rudy::Vector2f startPosition = Rudy::ImGuiLayoutCommands::GetCursorPosition();
		Rudy::Vector2f itemCursorPosition = Rudy::ImGuiLayoutCommands::GetCursorPosition();
		for (unsigned int subFolderIndex = 0; subFolderIndex < subFolders.GetCursor(); subFolderIndex++)
		{
			/*
			* Get sub folder
			*/
			DomainFolderView* subFolder = subFolders[subFolderIndex];

			/*
			* Render sub folder as button
			*/
			const Rudy::Vector2f itemStartPosition = itemCursorPosition;
			Rudy::ImGuiLayoutCommands::SetCursorPosition(itemCursorPosition);
			if (Rudy::ImGuiRenderCommands::CreateTexturedButton(subFolder->GetName(), m_FolderIconSize,m_FolderIconTexture))
			{
				nextFrameFolderView = subFolder;
			}

			/*
			* Cache whether the folder is havored or not
			*/
			const bool isFolderHavored = Rudy::ImGuiEventCommands::IsCurrentItemHavored();

			/*
			* Cache next item position
			*/
			const Rudy::Vector2f nextItemPosition = Rudy::ImGuiLayoutCommands::GetCursorPosition();

			/*
			* Create folder text
			*/
			Rudy::ImGuiLayoutCommands::SetCursorPosition(itemStartPosition + Rudy::Vector2f(0,m_FolderIconSize.Y + m_ItemPadding.Y));
			Rudy::ImGuiRenderCommands::CreateText(subFolder->GetName());

			/*
			* Validate next line
			*/
			const float nextPositionHorizontal = itemCursorPosition.X + m_FolderIconSize.X*2 + m_ItemPadding.X;
			if (nextPositionHorizontal >= itemAvailableSpace.X)
			{
				itemCursorPosition.X = startPosition.X;
				itemCursorPosition.Y += m_FolderIconSize.Y + m_ItemPadding.Y + m_ItemTextSize;
			}
			else
			{
				itemCursorPosition.X += m_FolderIconSize.X + m_ItemPadding.X;
			}
			
			/*
			* Validate and render folder quick menu
			*/
			if (isFolderHavored && Rudy::ImGuiEventCommands::IsMouseButtonClicked(Rudy::GUIMouseButtons::Right))
			{
				nextFrameQuickFolderView = subFolder;
				Rudy::ImGuiRenderCommands::SignalPopup("Folder_Quick_Menu");
			}
		}

		/*
		* Render assets
		*/
		const Rudy::Array<DomainAssetView*> assets = m_CurrentFolderView->GetAssets();
		for (unsigned int assetIndex = 0; assetIndex < assets.GetCursor(); assetIndex++)
		{
			/*
			* Get asset
			*/
			DomainAssetView* assetView = assets[assetIndex];

			/*
			* Render asset
			*/
			Rudy::ImGuiLayoutCommands::SetCursorPosition(itemCursorPosition);
			if (Rudy::ImGuiRenderCommands::CreateButton(assetView->GetAssetName(), m_FolderIconSize))
			{
				printf("Asset seþected: %s\n", *assetView->GetAssetName());
			}

			/*
			* Cache whether the asset is havored or not
			*/
			const bool isAssetHavored = Rudy::ImGuiEventCommands::IsCurrentItemHavored();

			/*
			* Validate next line
			*/
			const float nextPositionHorizontal = itemCursorPosition.X + m_AssetIconSize.X * 2 + m_ItemPadding.X;
			if (nextPositionHorizontal >= itemAvailableSpace.X)
			{
				itemCursorPosition.X = startPosition.X;
				itemCursorPosition.Y += m_AssetIconSize.Y + m_ItemPadding.Y;
			}
			else
			{
				itemCursorPosition.X += m_AssetIconSize.X + m_ItemPadding.X;
			}

			/*
			* Validate and render asset quick menu
			*/
			if (isAssetHavored && Rudy::ImGuiEventCommands::IsMouseButtonClicked(Rudy::GUIMouseButtons::Right))
			{
				nextFrameQuickAssetView = assetView;
				Rudy::ImGuiRenderCommands::SignalPopup("Asset_Quick_Menu");
			}
		}

		/*
		* Validate and render folder quick menu
		*/
		if (m_CurrentQuickMenuFolderView != nullptr && Rudy::ImGuiRenderCommands::BeginPopup("Folder_Quick_Menu"))
		{
			Rudy::ImGuiRenderCommands::CreateImage(m_FolderRenameTexture, Rudy::Vector2f(DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE, DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE));
			Rudy::ImGuiLayoutCommands::StayHere();
			if (Rudy::ImGuiRenderCommands::CreateMenuItem("Rename"))
			{

			}

			Rudy::ImGuiRenderCommands::CreateImage(m_FolderDeleteTexture, Rudy::Vector2f(DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE, DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE));
			Rudy::ImGuiLayoutCommands::StayHere();
			if (Rudy::ImGuiRenderCommands::CreateMenuItem("Delete"))
			{

			}
			Rudy::ImGuiRenderCommands::FinalizePopup();
		}

		/*
		* Validate and render asset quick menu
		*/
		if (m_CurrentQuickMenuAssetView != nullptr && Rudy::ImGuiRenderCommands::BeginPopup("Asset_Quick_Menu"))
		{
			Rudy::ImGuiRenderCommands::CreateImage(m_AssetRenameTexture, Rudy::Vector2f(DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE, DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE));
			Rudy::ImGuiLayoutCommands::StayHere();
			if (Rudy::ImGuiRenderCommands::CreateMenuItem("Rename"))
			{

			}

			Rudy::ImGuiRenderCommands::CreateImage(m_AssetDeleteTexture, Rudy::Vector2f(DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE, DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE));
			Rudy::ImGuiLayoutCommands::StayHere();
			if (Rudy::ImGuiRenderCommands::CreateMenuItem("Delete"))
			{

			}
			Rudy::ImGuiRenderCommands::FinalizePopup();
		}

		/*
		* Validate and render asset create context menu popup
		*/
		if (!Rudy::ImGuiEventCommands::IsAnyItemHavored() &&
			Rudy::ImGuiEventCommands::IsWindowFocused() &&
			Rudy::ImGuiEventCommands::IsMouseButtonClicked(Rudy::GUIMouseButtons::Right))
		{
			Rudy::ImGuiRenderCommands::SignalPopup("Asset_Create_Popup");
		}
		if (Rudy::ImGuiRenderCommands::BeginPopup("Asset_Create_Popup"))
		{
			if (Rudy::ImGuiRenderCommands::BeginMenu("Graphics"))
			{
				if (Rudy::ImGuiRenderCommands::CreateMenuItem("Shader"))
				{

				}
				if (Rudy::ImGuiRenderCommands::CreateMenuItem("Shader Program"))
				{

				}
				if (Rudy::ImGuiRenderCommands::CreateMenuItem("Material"))
				{

				}
				if (Rudy::ImGuiRenderCommands::CreateMenuItem("Framebuffer2D"))
				{

				}
				Rudy::ImGuiRenderCommands::FinalizeMenu();
			}
			if (Rudy::ImGuiRenderCommands::BeginMenu("Compute"))
			{
				if (Rudy::ImGuiRenderCommands::CreateMenuItem("Compute Shader"))
				{

				}
				if (Rudy::ImGuiRenderCommands::CreateMenuItem("GPGPU Kernel"))
				{

				}

				Rudy::ImGuiRenderCommands::FinalizeMenu();
			}
			if (Rudy::ImGuiRenderCommands::CreateMenuItem("Folder"))
			{

			}
			if (Rudy::ImGuiRenderCommands::CreateMenuItem("World"))
			{

			}
			Rudy::ImGuiRenderCommands::FinalizePopup();
		}

		/*
		* Validate if clicked to empty space 
		*/
		if (Rudy::ImGuiEventCommands::IsWindowFocused() && Rudy::ImGuiEventCommands::IsWindowHavored() && !Rudy::ImGuiEventCommands::IsAnyItemHavored() &&
			(Rudy::ImGuiEventCommands::IsMouseButtonClicked(Rudy::GUIMouseButtons::Left) || Rudy::ImGuiEventCommands::IsMouseButtonClicked(Rudy::GUIMouseButtons::Right))
			)
		{
			nextFrameQuickFolderView = nullptr;
			nextFrameQuickAssetView = nullptr;
		}


		/*
		* Validate and gather drag drop paths
		*/
		if (Rudy::ImGuiEventCommands::IsWindowHavored /* && XInput->GetFileDropEvent() != nullptr */)
		{
			Rudy::Array<Rudy::String> drops;
			/*
			* Iterate each file drop
			*/
			for (unsigned int i = 0; i < drops.GetCursor(); i++)
			{
				/*
				* Get file drop path
				*/
				const Rudy::String dropPath = drops[i];

				/*
				* Get file extension
				*/
				const Rudy::String dropFileExtension = Rudy::PlatformFile::GetFileExtension(dropPath);

				/*
				* Catch file type
				*/

			}
		}

		/*
		* Set next frame properties
		*/
		m_CurrentFolderView = nextFrameFolderView;
		m_CurrentQuickMenuFolderView = nextFrameQuickFolderView;
		m_CurrentQuickMenuAssetView = nextFrameQuickAssetView;
	}
	void DomainObserverGUIWindow::OnLayoutFinalize()
	{

	}
	void DomainObserverGUIWindow::OnVisible()
	{

	}
	void DomainObserverGUIWindow::OnInvisible()
	{

	}
}