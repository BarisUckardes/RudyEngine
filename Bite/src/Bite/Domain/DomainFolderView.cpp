#include "DomainFolderView.h"
#include <Rudy/Platform/Utility/PlatformDirectory.h>
namespace Bite
{
	DomainFolderView::DomainFolderView(DomainFolderView* parentFolder, const Rudy::String& selfPath)
	{
		/*
		* Set folder properties
		*/
		m_ParentFolder = parentFolder;
		m_AbsolutePath = selfPath;
		m_ID = Rudy::Guid::Create();

		/*
		* Gather folders
		*/
		Rudy::Array<Rudy::String> folderPaths;
		Rudy::PlatformDirectory::GetFoldersInDirectory(selfPath, folderPaths);
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

			/*
			* Register folder view
			*/
			m_SubFolders.Add(subFolder);
		}

		/*
		* Create file views
		*/
		Rudy::Array<Rudy::String> assetPaths;
		Rudy::PlatformDirectory::GetFilesInDirectoryViaExtension(selfPath, ".rasset",assetPaths);
		for (int i = 0; i < assetPaths.GetCursor(); i++)
		{
			/*
			* Get asset path
			*/
			const Rudy::String& filePath = assetPaths[i];

			/*
			* Create file view
			*/
			DomianAssetView* assetView = nullptr;

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
	Rudy::Array<DomianAssetView*> DomainFolderView::GetAssets() const
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