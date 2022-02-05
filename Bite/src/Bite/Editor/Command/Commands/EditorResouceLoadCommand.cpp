#include "EditorResouceLoadCommand.h"
#include <Rudy/Asset/AssetPackage.h>
#include <Rudy/Asset/Asset.h>
#include <Rudy/Asset/AssetPool.h>
#include <Bite/Editor/Session/EditorSession.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Platform/Utility/PlatformPaths.h>
#include <Bite/Editor/Resource/EditorResource.h>
#include <stdio.h>
namespace Bite
{
	EditorResouceLoadCommand::EditorResouceLoadCommand(const Rudy::Array<Rudy::AssetType>& assetTypes, const Rudy::Array<Rudy::String>& assetNames)
	{
		m_AssetTypes = assetTypes;
		m_AssetNames = assetNames;
	}
	void EditorResouceLoadCommand::OnInitialize()
	{
		/*
		* Create new virtual package
		*/
		m_EditorResourcePackage = GetOwnerSession()->GetApplicationSession()->GetAssetPool()->CreateVirtualPackage();

		/*
		* Load resources
		*/
		Rudy::Array<EditorResource*> resources;
		for (unsigned int i = 0; i < m_AssetTypes.GetCursor(); i++)
		{
			/*
			* Get asset type
			*/
			const Rudy::AssetType assetType = m_AssetTypes[i];

			/*
			* Get asset names
			*/
			const Rudy::String assetName = m_AssetNames[i];

			/*
			* Create absolute path
			*/
			Rudy::String absolutePath = Rudy::PlatformPaths::GetProgramFilesPath() + "Rudy/Bite/Resources/" + assetName;

			/*
			* Load resources
			*/
			resources.Add(new EditorResource(GetOwnerSession(), m_EditorResourcePackage, assetType, absolutePath,assetName, false));
		}

		/*
		* Set editor resources
		*/
		GetOwnerSession()->SetEditorResources(resources);

	}
	void EditorResouceLoadCommand::OnFinalize()
	{
		m_EditorResourcePackage->UnloadPackage();
		delete m_EditorResourcePackage;
	}
}