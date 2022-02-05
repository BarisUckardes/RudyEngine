#include "DomainObserverGUIWindow.h"
#include <Rudy/ImGui/Commands/ImGuiCommands.h>
#include <Bite/Editor/Session/EditorSession.h>
#include <Bite/Domain/DomainView.h>
#include <Bite/Domain/DomainFolderView.h>
#include <Bite/Domain/DomainAssetView.h>
#include <Rudy/Graphics/Texture/Texture2D.h>
#include <stdio.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Bite/GUI/Painter/GUIPainterEventLedger.h>
#include <Bite/GUI/Painter/GUIPainter.h>
#include <Rudy/Input/Keys.h>
#include <Rudy/Graphics/Shader/ShaderStage.h>
namespace Bite
{
	GENERATE_REFLECTABLE_TYPE(DomainObserverGUIWindow)
	GENERATE_WINDOW_GENERATOR(DomainObserverGUIWindow);

	#define DEFAULT_ITEM_PADDING_HORIZONTAL 24
	#define DEFAULT_ITEM_PADDING_VERTICAL 8
	#define DEFAULT_FOLDER_ICON_SIZE 64
	#define DEFAULT_ASSET_ICON_SIZE 64
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
		* Get render commands
		*/
		const Rudy::ImGuiRenderCommands* renderCommands = GetPainter()->GetRenderCommands();
		const Rudy::ImGuiLayoutCommands* layoutCommands = GetPainter()->GetLayoutCommands();
		const GUIPainterEventLedger* eventLedger = GetPainter()->GetEventLedger();

		/*
		* Next frame properties
		*/
		DomainFolderView* nextFrameFolderView = m_CurrentFolderView;
		DomainFolderView* nextFrameQuickFolderView = m_CurrentQuickMenuFolderView;
		DomainAssetView* nextFrameQuickAssetView = m_CurrentQuickMenuAssetView;

		/*
		* Render current folder path
		*/
		if (m_CurrentFolderView->GetParentFolder() != nullptr && renderCommands->CreateButton("Back"))
		{
			nextFrameFolderView = m_CurrentFolderView->GetParentFolder();
		}
		layoutCommands->StayHere();
		renderCommands->CreateText(m_CurrentFolderView->GetAbsolutePath());
		renderCommands->CreateHorizontalLine();

		/*
		* Render folders
		*/
		Rudy::Array<DomainFolderView*> subFolders = m_CurrentFolderView->GetSubFolders();
		const Rudy::Vector2f itemAvailableSpace = layoutCommands->GetAvailableSpace();
		const Rudy::Vector2f startPosition = layoutCommands->GetCursorPosition();
		Rudy::Vector2f itemCursorPosition = layoutCommands->GetCursorPosition();
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
			layoutCommands->SetCursorPosition(itemCursorPosition);
			if (renderCommands->CreateTexturedButton(subFolder->GetName(), m_FolderIconSize,m_FolderIconTexture))
			{
				nextFrameFolderView = subFolder;
			}

			/*
			* Cache whether the folder is havored or not
			*/
			const bool isFolderHavored = eventLedger->IsCurrentItemHavored();

			/*
			* Cache next item position
			*/
			const Rudy::Vector2f nextItemPosition = layoutCommands->GetCursorPosition();

			/*
			* Create folder text
			*/
			layoutCommands->SetCursorPosition(itemStartPosition + Rudy::Vector2f(0,m_FolderIconSize.Y + m_ItemPadding.Y));
			renderCommands->CreateText(subFolder->GetName());

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
			if (isFolderHavored && eventLedger->IsMouseButtonDown(RUDY_MOUSE_BUTTON_RIGHT))
			{
				nextFrameQuickFolderView = subFolder;
				renderCommands->SignalPopup("Folder_Quick_Menu");
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
			const Rudy::Vector2f itemStartPosition = itemCursorPosition;
			layoutCommands->SetCursorPosition(itemCursorPosition);
			if (renderCommands->CreateTexturedButton(assetView->GetAssetName(), m_AssetIconSize, m_FolderRenameTexture))
			{

			}

			/*
			* Cache whether the asset is havored or not
			*/
			const bool isAssetHavored = eventLedger->IsCurrentItemHavored();


			/*
			* Cache next item position
			*/
			const Rudy::Vector2f nextItemPosition = layoutCommands->GetCursorPosition();

			/*
			* Create folder text
			*/
			layoutCommands->SetCursorPosition(itemStartPosition + Rudy::Vector2f(0, m_AssetIconSize.Y + m_ItemPadding.Y));
			renderCommands->CreateText(assetView->GetAssetName());

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
			if (isAssetHavored && eventLedger->IsMouseButtonDown(RUDY_MOUSE_BUTTON_RIGHT))
			{
				nextFrameQuickAssetView = assetView;
				renderCommands->SignalPopup("Asset_Quick_Menu");
			}

			/*
			* Try asset to load
			*/
			assetView->TryLoadAsset(false);
		}

		/*
		* Validate and render folder quick menu
		*/
		if (m_CurrentQuickMenuFolderView != nullptr && renderCommands->BeginPopup("Folder_Quick_Menu"))
		{
			renderCommands->CreateImage(m_FolderRenameTexture, Rudy::Vector2f(DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE, DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE));
			layoutCommands->StayHere();
			if (renderCommands->CreateMenuItem("Rename"))
			{

			}

			renderCommands->CreateImage(m_FolderDeleteTexture, Rudy::Vector2f(DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE, DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE));
			layoutCommands->StayHere();
			if (renderCommands->CreateMenuItem("Delete"))
			{

			}
			renderCommands->FinalizePopup();
		}

		/*
		* Validate and render asset quick menu
		*/
		if (m_CurrentQuickMenuAssetView != nullptr && renderCommands->BeginPopup("Asset_Quick_Menu"))
		{
			renderCommands->CreateImage(m_AssetRenameTexture, Rudy::Vector2f(DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE, DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE));
			layoutCommands->StayHere();
			if (renderCommands->CreateMenuItem("Rename"))
			{

			}

			renderCommands->CreateImage(m_AssetDeleteTexture, Rudy::Vector2f(DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE, DEFAULT_FOLDER_QUICK_MENU_ITEM_SIZE));
			layoutCommands->StayHere();
			if (renderCommands->CreateMenuItem("Delete"))
			{

			}
			renderCommands->FinalizePopup();
		}

		/*
		* Validate and render asset create context menu popup
		*/
		if (!eventLedger->IsAnyItemHavored() &&
			eventLedger->IsWindowFocused() &&
			eventLedger->IsMouseButtonDown(RUDY_MOUSE_BUTTON_RIGHT))
		{
			renderCommands->SignalPopup("Asset_Create_Popup");
		}
		if (renderCommands->BeginPopup("Asset_Create_Popup"))
		{
			if (renderCommands->BeginMenu("Graphics"))
			{
				if (renderCommands->CreateMenuItem("Shader"))
				{
					Rudy::ShaderStage stage = Rudy::ShaderStage::Vertex;
					m_CurrentFolderView->CreateAsset("Mah_shader_asset", Rudy::AssetType::Shader, &stage);
				}
				if (renderCommands->CreateMenuItem("Shader Program"))
				{
					m_CurrentFolderView->CreateAsset("Mag_shader_program", Rudy::AssetType::ShaderProgram, nullptr);
				}
				if (renderCommands->CreateMenuItem("Material"))
				{

				}
				if (renderCommands->CreateMenuItem("Framebuffer2D"))
				{

				}
				renderCommands->FinalizeMenu();
			}
			if (renderCommands->BeginMenu("Compute"))
			{
				if (renderCommands->CreateMenuItem("Compute Shader"))
				{

				}
				if (renderCommands->CreateMenuItem("GPGPU Kernel"))
				{

				}

				renderCommands->FinalizeMenu();
			}
			if (renderCommands->CreateMenuItem("Folder"))
			{
				/*
				* Create sub folder
				*/
				m_CurrentFolderView->CreateSubFolder("TETET");
			}
			if (renderCommands->CreateMenuItem("World"))
			{

			}
			renderCommands->FinalizePopup();
		}

		/*
		* Validate if clicked to empty space 
		*/
		if (eventLedger->IsWindowFocused() && eventLedger->IsWindowHavored() &&
			!eventLedger->IsAnyItemHavored() &&
			(eventLedger->IsMouseButtonDown(RUDY_MOUSE_BUTTON_RIGHT) || eventLedger->IsMouseButtonDown(RUDY_MOUSE_BUTTON_LEFT))
			)
		{
			nextFrameQuickFolderView = nullptr;
			nextFrameQuickAssetView = nullptr;
		}


		/*
		* Validate and gather drag drop paths
		*/
		const Rudy::Array<Rudy::String> fileDrops = eventLedger->GetFileDrops();
		if (eventLedger->IsWindowHavored())
		{
			
			/*
			* Iterate each file drop
			*/
			for (unsigned int i = 0; i < fileDrops.GetCursor(); i++)
			{
				/*
				* Get file drop path
				*/
				const Rudy::String dropPath = fileDrops[i];

				/*
				* Get file extension
				*/
				Rudy::String dropFileExtension;
				Rudy::PlatformFile::GetFileExtension(dropPath,dropFileExtension);

				/*
				* Catch file type
				*/
				if (dropFileExtension == ".png" || dropFileExtension == ".jpg" || dropFileExtension == ".jpeg") // validate image
				{
					/*
					* Create new image asset
					*/

					
				}
				if (dropFileExtension == ".obj" || dropFileExtension == ".fbx") // validate mesh
				{
					/*
					* Create new mesh asset
					*/
				}
				if (dropFileExtension == ".wav") // validate sound file
				{

				}
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