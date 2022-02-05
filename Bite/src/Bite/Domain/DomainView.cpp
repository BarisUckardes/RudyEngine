#include "DomainView.h"
#include <Rudy/Platform/Utility/PlatformDirectory.h>
#include <stdio.h>
#include <Bite/Domain/DomainFolderView.h>
namespace Bite
{
	DomainView::DomainView(const Rudy::String& domainPath,EditorSession* ownerSession)
	{
		/*
		* Set properties
		*/
		m_DomainPath = domainPath;
		m_OwnerSession = ownerSession;

		/*
		* Initialize
		*/
		Initialize();
	}
	DomainView::~DomainView()
	{

	}
	DomainFolderView* DomainView::GetRootFolder() const
	{
		return m_RootFolder;
	}
	void DomainView::Initialize()
	{
		/*
		* Collect folders
		*/
		Rudy::Array<Rudy::String> folderPaths;
		if (!Rudy::PlatformDirectory::GetFoldersInDirectory(m_DomainPath + "/", folderPaths))
		{
		}

		/*
		* Collect files
		*/
		Rudy::Array<Rudy::String> filePaths;
		if (!Rudy::PlatformDirectory::GetFilesInDirectoryViaExtension(m_DomainPath + "/", ".rasset", filePaths))
		{

		}

		/*
		* Create folder view for the root folder
		*/
		m_RootFolder = new DomainFolderView(nullptr,m_DomainPath,m_OwnerSession);
	}
}