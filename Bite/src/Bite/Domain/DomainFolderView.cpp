#include "DomainFolderView.h"
#include <Rudy/Platform/Utility/PlatformDirectory.h>
#include <Bite/Domain/DomainAssetView.h>
#include <stdio.h>
namespace Bite
{
	DomainFolderView::DomainFolderView(DomainFolderView* parentFolder, const Rudy::String& selfPath)
	{
		/*
		* Set folder properties
		*/
		m_ParentFolder = parentFolder;
		m_AbsolutePath = selfPath;
		m_Name = Rudy::PlatformDirectory::GetFolderNameFromPath(selfPath);
		m_ID = Rudy::Guid::Create();

		/*
		* Gather folders
		*/
		Rudy::Array<Rudy::String> folderPaths;
		Rudy::PlatformDirectory::GetFoldersInDirectory(m_AbsolutePath + "/", folderPaths);
		for (int i = 0; i < folderPaths.GetCursor(); i++)
		{
			/*
			* Get folder path
			*/
			const Rudy::String& folderPath = folderPaths[i];

			/*
			* Create sub folder view
			*/
			DomainFolderView* subFolder = new DomainFolderView(this,folderPath);
			printf("Found folder: [%s]\n", *subFolder->GetName());

			/*
			* Register folder view
			*/
			m_SubFolders.Add(subFolder);
		}

		/*
		* Create file views
		*/
		Rudy::Array<Rudy::String> assetPaths;
		Rudy::PlatformDirectory::GetFilesInDirectoryViaExtension(m_AbsolutePath + "/", ".rasset",assetPaths);
		for (int i = 0; i < assetPaths.GetCursor(); i++)
		{
			/*
			* Get asset path
			*/
			const Rudy::String& filePath = assetPaths[i];

			/*
			* Create file view
			*/
			DomainAssetView* assetView = nullptr;
			printf("Found asset: [%s]\n", *assetView->GetAssetName());

			/*
			* Register asset view
			*/
			m_Assets.Add(assetView);
		}
	}
	Rudy::Array<DomainFolderView*> DomainFolderView::GetSubFolders() const
	{
		return m_SubFolders;
	}
	Rudy::Array<DomainAssetView*> DomainFolderView::GetAssets() const
	{
		return m_Assets;
	}
	DomainFolderView* DomainFolderView::GetParentFolder() const
	{
		return m_ParentFolder;
	}
	Rudy::Guid DomainFolderView::GetID() const
	{
		return m_ID;
	}
	Rudy::String DomainFolderView::GetName() const
	{
		return m_Name;
	}
	Rudy::String DomainFolderView::GetAbsolutePath() const
	{
		return m_AbsolutePath;
	}
}