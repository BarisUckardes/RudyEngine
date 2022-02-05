#include "EditorSession.h"
#include <stdio.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Application/Windowing/Window.h>
#include <Bite/Domain/DomainView.h>
#include <Rudy/Platform/Utility/PlatformPaths.h>
#include <Rudy/Platform/Utility/PlatformDirectory.h>
#include <Bite/Editor/Resource/EditorResource.h>
#include <Rudy/Asset/AssetPackage.h>
#include <Rudy/Asset/AssetPool.h>
namespace Bite
{
	EditorSession::EditorSession(Rudy::ApplicationSession* applicationSession,GUIPainter* painter)
	{
		m_ApplicationSession = applicationSession;
		m_Painter = painter;

		/*
		* Create editor asset pakcage
		*/
		m_AssetPackage = applicationSession->GetAssetPool()->CreateVirtualPackage();

		/*
		* Initialize domain view
		*/
		m_DomainView = new DomainView(Rudy::PlatformPaths::GetDomainPath(),this);

	}
	EditorSession::~EditorSession()
	{
		m_ApplicationSession = nullptr;
	}
	Rudy::ApplicationSession* EditorSession::GetApplicationSession() const
	{
		return m_ApplicationSession;
	}
	DomainView* EditorSession::GetDomainView() const
	{
		return m_DomainView;
	}
	Rudy::String EditorSession::GetProjectName() const
	{
		return m_ProjectProperties.Name;
	}
	const ProjectProperties& EditorSession::GetProjectProperties() const
	{
		return m_ProjectProperties;
	}
	Rudy::AssetObject* EditorSession::GetEditorResource(Rudy::AssetType type, const Rudy::String& name)
	{
		/*
		* Try get editor resource
		*/
		for (int i = 0; i < m_EditorResources.GetCursor(); i++)
		{
			/*
			* Get editor resource
			*/
			const EditorResource* resource = m_EditorResources[i];

			/*
			* Validate
			*/
			if (type == resource->GetAssetType() && name == resource->GetName())
			{
				return resource->GetResourceObject();
			}
				

		}
		return nullptr;
	}
	GUIPainter* EditorSession::GetSessionPainter() const
	{
		return m_Painter;
	}
	Rudy::AssetPackage* EditorSession::GetEditorAssetPackage() const
	{
		return m_AssetPackage;
	}
	void EditorSession::SetProject(const Rudy::String& name, unsigned int major, unsigned int minor, const Rudy::Guid& id)
	{
		/*
		* Set project properties
		*/
		m_ProjectProperties.Name = name;
		m_ProjectProperties.MajorVersion = major;
		m_ProjectProperties.MinorVersion = minor;
		m_ProjectProperties.ID = id;

		/*
		* Set window title
		*/
		GetApplicationSession()->GetSessionWindow()->SetTitle(name);

	/*	printf("Project settings adjusted as...\n");
		printf("	Name: %s\n",*name);
		printf("	Major Version: %d\n",major);
		printf("	Minor Version: %d\n",minor);
		printf("	Project ID: %s\n",*id.GetAsString());*/
	}
	void EditorSession::SetEditorResources(const Rudy::Array<EditorResource*>& resources)
	{
		m_EditorResources = resources;
	}
}