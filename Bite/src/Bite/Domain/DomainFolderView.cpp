#include "DomainFolderView.h"
#include <Rudy/Platform/Utility/PlatformDirectory.h>
#include <Bite/Domain/DomainAssetView.h>
#include <Rudy/Graphics/Shader/ShaderStage.h>
#include <Rudy/Asset/Containers/ShaderContainer.h>
#include <stdio.h>
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Asset/AssetHeaderGenerator.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Core/Log.h>
#include <Rudy/Asset/AssetWriteConstants.h>
#include <Bite/Domain/Assets/AssetWriters.h>
#include <Bite/Editor/Session/EditorSession.h>

namespace Bite
{

	DomainFolderView::DomainFolderView(DomainFolderView* parentFolder, const Rudy::String& selfPath,EditorSession* ownerSession)
	{
		/*
		* Set folder properties
		*/
		m_ParentFolder = parentFolder;
		m_AbsolutePath = selfPath;
		m_Name = Rudy::PlatformDirectory::GetFolderNameFromPath(selfPath);
		m_ID = Rudy::Guid::Create();
		m_OwnerSession = ownerSession;

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
			DomainFolderView* subFolder = new DomainFolderView(this,folderPath, ownerSession);

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
			DomainAssetView* assetView = new DomainAssetView(filePath, ownerSession);

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
	void DomainFolderView::CreateSubFolder(const Rudy::String& folderName)
	{
		/*
		* Create folder absolute path
		*/
		const Rudy::String absolutePath = m_AbsolutePath + "/" + folderName;

		/*
		* Create physical folder
		*/
		Rudy::PlatformDirectory::CreateDirectory(absolutePath);

		/*
		* Create sub folder view
		*/
		m_SubFolders.Add(new DomainFolderView(this, absolutePath,m_OwnerSession));
	}
	void DomainFolderView::CreateAsset(const Rudy::String& name, Rudy::AssetType assetType,void* parameter)
	{
		/*
		* Generate asset path
		*/
		Rudy::String assetPath = m_AbsolutePath + "/" + name + ".rasset";
		Rudy::ByteBlock headerBytes;
		Rudy::ByteBlock assetContentBytes;

		/*
		* Generate asset header
		*/
		Rudy::AssetHeaderContainer header;
		header.Type = assetType;
		header.ID = Rudy::Guid::Create();
		Rudy::Memory::MemoryCopy(&header.Name, (void*)*name, name.GetCursor() + 1);
		header.Offset = sizeof(Rudy::AssetHeaderContainer);

		/*
		* Catch asset type and generate source file
		*/
		switch (assetType)
		{
			case Rudy::AssetType::Undefined:
				break;
			case Rudy::AssetType::Prefab:
				break;
			case Rudy::AssetType::World:
			{
				/*
				* Create default per world data
				*/

				/*
				* Create dummy world data
				*/


				break;
			}
			case Rudy::AssetType::Texture1D:
				break;
			case Rudy::AssetType::Texture2D:
				break;
			case Rudy::AssetType::Texture3D:
				break;
			case Rudy::AssetType::CubeTexture:
				break;
			case Rudy::AssetType::Material:
				break;
			case Rudy::AssetType::Shader:
			{
				/*
				* Get requested shader stage
				*/
				Rudy::ShaderStage stage = *(Rudy::ShaderStage*)parameter;

				/*
				* Create shader default source
				*/
				Rudy::String sourceText = "No Shader source";

				/*
				* Create shader write parameters
				*/
				ShaderWriteParameters parameters = { stage,sourceText };

				/*
				* Write asset contets
				*/
				ShaderAssetWriter writer(m_OwnerSession->GetApplicationSession());
				writer.Write(&parameters, assetContentBytes);

				/*
				* Set header target asset  size
				*/
				header.Size = 4 + sourceText.GetCursor();

				break;
			}
			case Rudy::AssetType::ShaderProgram:
			{
				/*
				* Get shader program parameter
				*/
				Rudy::String programName = "Default program name";
				Rudy::String categoryName = "Default category name";
				Rudy::Array<Rudy::Shader*> shaders;

				/*
				* Create shader program write parameters
				*/
				ShaderProgramWriteParameters parameters = { programName,categoryName,shaders };
			
				/*
				* Write asset contets
				*/
				ShaderProgramAssetWriter writer(m_OwnerSession->GetApplicationSession());
				writer.Write(&parameters, assetContentBytes);

				/*
				* Set header target asset size
				*/
				header.Size = ASSET_WRITE_MAX_NAME + ASSET_WRITE_MAX_NAME + 4u + sizeof(unsigned char*)*shaders.GetCursor();

				break;
			}
			case Rudy::AssetType::Mesh:
				break;
			case Rudy::AssetType::Framebuffer2D:
				break;
			default:
				break;
		}
		
		/*
		* Generate header bytes
		*/
		headerBytes = Rudy::AssetHeaderGenerator::GenerateByteBlock(header);

		/*
		* Write header to file
		*/
		Rudy::PlatformFile::Write(assetPath, headerBytes);

		/*
		* Write shader content to file
		*/
		Rudy::PlatformFile::WriteAppend(assetPath,assetContentBytes);

		/*
		* Generate new DomainAssetView with written file
		*/
		DomainAssetView* assetView = new DomainAssetView(assetPath, m_OwnerSession);

		/*
		* Register asset view
		*/
		m_Assets.Add(assetView);
	}
}