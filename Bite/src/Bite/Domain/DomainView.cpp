#include "DomainView.h"
#include <Rudy/Platform/Utility/PlatformDirectory.h>
#include <stdio.h>
#include <Bite/Domain/DomainFolderView.h>
namespace Bite
{
	DomainView::DomainView(const Rudy::String& domainPath,Rudy::AssetPackage* package)
	{
		/*
		* Set domain path
		*/
		m_DomainPath = domainPath;

		/*
		* Initialize
		*/
		Initialize(package);
	}
	DomainView::~DomainView()
	{

	}
	DomainFolderView* DomainView::GetRootFolder() const
	{
		return m_RootFolder;
	}
	void DomainView::Initialize(Rudy::AssetPackage* package)
	{
		/*
		* Collect folders
		*/
		printf("Domain View Initialization started...\n");
		Rudy::Array<Rudy::String> folderPaths;
		if (!Rudy::PlatformDirectory::GetFoldersInDirectory(m_DomainPath + "/", folderPaths))
		{
			printf("	Loading folder paths failed!\n");
		}

		/*
		* Collect files
		*/
		Rudy::Array<Rudy::String> filePaths;
		if (!Rudy::PlatformDirectory::GetFilesInDirectoryViaExtension(m_DomainPath + "/", ".rasset", filePaths))
		{
			printf("	Loading .rasset files failed\n");
		}

		/*
		* Create folder view for the root folder
		*/
		m_RootFolder = new DomainFolderView(nullptr,m_DomainPath,package);
		printf("Domain View Initialization finished.!\n");
	}
}