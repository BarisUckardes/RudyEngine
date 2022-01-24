#include "DomainObserverGUIWindow.h"
#include <Rudy/ImGui/Commands/ImGuiCommands.h>
#include <Bite/Editor/Session/EditorSession.h>
#include <Bite/Domain/DomainView.h>
#include <Bite/Domain/DomainFolderView.h>
#include <Bite/Domain/DomainAssetView.h>
#include <Rudy/Graphics/Texture/Texture2D.h>
#include <stdio.h>
namespace Bite
{
	GENERATE_REFLECTABLE_TYPE(DomainObserverGUIWindow);
	GENERATE_WINDOW_GENERATOR(DomainObserverGUIWindow);

	#define DEFAULT_ITEM_PADDING_HORIZONTAL 8
	#define DEFAULT_ITEM_PADDING_VERTICAL 8
	#define DEFAULT_FOLDER_ICON_SIZE 64
	#define DEFAULT_ASSET_ICON_SIZE 48
	#define DEFAULT_ITEM_TEXT_SIZE 16
	
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
	}
	void DomainObserverGUIWindow::OnLayoutRender()
	{
		/*
		* Next frame properties
		*/
		DomainFolderView* nextFrameFolderView = m_CurrentFolderView;

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
				printf("Set next folder: %s\n", *subFolder->GetName());
			}

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
			DomainAssetView* asset = assets[assetIndex];

			/*
			* Render asset
			*/
			Rudy::ImGuiLayoutCommands::SetCursorPosition(itemCursorPosition);
			if (Rudy::ImGuiRenderCommands::CreateButton(asset->GetAssetName(), m_FolderIconSize))
			{
				printf("Asset seþected: %s\n", *asset->GetAssetName());
			}

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
		* Set next frame properties
		*/
		m_CurrentFolderView = nextFrameFolderView;
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