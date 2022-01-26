#include "DomainFolderView.h"
#include <Rudy/Platform/Utility/PlatformDirectory.h>
#include <Bite/Domain/DomainAssetView.h>
#include <Rudy/Graphics/Shader/ShaderStage.h>
#include <Rudy/Asset/Containers/ShaderContainer.h>
#include <stdio.h>
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Asset/AssetHeaderGenerator.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
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
		* Catch asset type and generate source file
		*/
		switch (assetType)
		{
			case Rudy::AssetType::Undefined:
				break;
			case Rudy::AssetType::Prefab:
				break;
			case Rudy::AssetType::World:
				break;
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
				* Generate new shader container
				*/
				Rudy::String sourceText = "No Shader source";

				/*
				* Generate header
				*/
				Rudy::AssetHeaderContainer header;
				header.Type = assetType;
				header.ID = Rudy::Guid::Create();
				Rudy::Memory::MemoryCopy(&header.Name, (void*)*name, name.GetCursor() +1);
				header.Offset = sizeof(Rudy::AssetHeaderContainer);
				header.Size = 4 + sourceText.GetCursor() + 1;

				/*
				* Generate byte block
				*/
				headerBytes = Rudy::AssetHeaderGenerator::GenerateByteBlock(header);

				/*
				* Generate shader content bytes
				*/
				Rudy::Byte* assetContentBuffer = new Rudy::Byte[4 + sourceText.GetCursor()];
				Rudy::Memory::MemoryCopy(assetContentBuffer, &stage, 4);
				Rudy::Memory::MemoryCopy((assetContentBuffer + 4), (char*) * sourceText, sourceText.GetCursor());
				assetContentBytes = Rudy::ByteBlock(assetContentBuffer,4 + sourceText.GetCursor());

				/*
				* Free allocated resources
				*/
				delete[] assetContentBuffer;
				break;
			}
			case Rudy::AssetType::ShaderProgram:
			{
				/*
				* Generate header
				*/
				Rudy::AssetHeaderContainer header;
				header.Type = assetType;
				header.ID = Rudy::Guid::Create();
				Rudy::Memory::MemoryCopy(&header.Name, (void*)*name, name.GetCursor() + 1);
				header.Offset = sizeof(Rudy::AssetHeaderContainer);
				header.Size = 4 + 20 + 20;

				/*
				* Generate header bytes
				*/
				headerBytes = Rudy::AssetHeaderGenerator::GenerateByteBlock(header);

				/*
				* Generate shader program content bytes
				*/
				const Rudy::String& shaderName = "Undefined shader name";
				const Rudy::String& shaderCategory = "Undefined shader category";
				const unsigned long shaderCount = 0;
				Rudy::Byte* assetContentBuffer = new Rudy::Byte[4 + 20 + 20];
				Rudy::Memory::MemoryCopy(assetContentBuffer, (void*)&shaderCount, sizeof(unsigned long));
				Rudy::Memory::MemoryCopy(assetContentBuffer, (void*)*shaderName, shaderName.GetCursor() + 1);
				Rudy::Memory::MemoryCopy((assetContentBuffer + 4 + 20), (void*)*shaderCategory, shaderCategory.GetCursor() + 1);
				assetContentBytes = Rudy::ByteBlock(assetContentBuffer, 4 + 20 +20);

				/*
				* Free allocated resources
				*/
				delete[] assetContentBuffer;
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
		m_Assets.Add(assetView);
	}
}