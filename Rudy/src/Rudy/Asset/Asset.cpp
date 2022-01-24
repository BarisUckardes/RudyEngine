#include "Asset.h"
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Graphics/Texture/Texture2D.h>
#include <Rudy/Asset/AssetPackage.h>
#include <Rudy/Asset/AssetPool.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <stdio.h>
namespace Rudy
{
	Asset::Asset(const AssetDefinition& definition,AssetPackage* ownerPackage,bool bTargetsRawFile)
	{
		m_LoadedObject = nullptr;
		m_OwnerPackage = ownerPackage;
		m_Definition = definition;
		m_bTargetsRawFile = bTargetsRawFile;
	}
	void Asset::Load(ApplicationSession* session)
	{
		/*
		* Validate if its loaded
		*/
		if (m_LoadedObject != nullptr)
			return;

		/*
		* Catch asset type and create asset
		*/
		AssetType type = m_Definition.GetType();
		RudyObject* loadedObject = nullptr;
		
		if (m_bTargetsRawFile)
		{
			switch (type)
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
				{
					/*
					* Load texture into memory
					*/
					Texture2DDiskLoadResult* result = Texture2D::LoadToMemoryFromDisk(m_Definition.GetSourceAbsolutePath());

					/*
					* Create new texture2d object
					*/
					Texture2D* texture = session->GetDefaultGraphicsDevice()->CreateTexture2D();

					/*
					* Initialize texture
					*/
					texture->Initialize(result->Width, result->Height,
						TextureFormat::Rgba, TextureInternalFormat::Rgba8,
						TextureDataType::UnsignedByte,
						TextureMinFilter::Nearest, TextureMagFilter::Linear,
						TextureWrapMode::Repeat ,TextureWrapMode::Repeat,false);

					/*
					* Set texture data
					*/
					texture->SetTextureData(result->NativaDataBlock, result->DataBlock.GetBlockSize());
					
					loadedObject = (RudyObject*)texture;
					break;
				}
				case Rudy::AssetType::Texture3D:
					break;
				case Rudy::AssetType::CubeTexture:
					break;
				case Rudy::AssetType::Material:
					break;
				case Rudy::AssetType::Shader:
					break;
				case Rudy::AssetType::ShaderProgram:
					break;
				case Rudy::AssetType::Mesh:
					break;
				case Rudy::AssetType::Framebuffer2D:
					break;
				default:
					break;
			}
		}
		else
		{
			/*
			* Load the asset bytes
			*/
			ByteBlock byteBlock;
			PlatformFile::Read(m_Definition.GetSourceAbsolutePath(),
				m_Definition.GetOffset(), m_Definition.GetOffset() + m_Definition.GetSize(),
				byteBlock);

			switch (type)
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
					break;
				case Rudy::AssetType::ShaderProgram:
					break;
				case Rudy::AssetType::Mesh:
					break;
				case Rudy::AssetType::Framebuffer2D:
					break;
				default:
					break;
			}
		}

		/*
		* Set loaded object
		*/
		m_LoadedObject = loadedObject;
	}
	void Asset::Cache(bool bCacheAsync)
	{
	}
	void Asset::DeleteCache()
	{
	}
	void Asset::Unload()
	{
		/*
		* Validate if its not loaded
		*/
		if (m_LoadedObject == nullptr)
			return;

		/*
		* Unload
		*/
		if(!m_LoadedObject->IsDestroyed())
			m_LoadedObject->Destroy();
		delete m_LoadedObject;
		m_LoadedObject = nullptr;
	}
	RudyObject* Asset::GetLoadedObject() const
	{
		return m_LoadedObject;
	}
	AssetPackage* Asset::GetOwnerPackage() const
	{
		return m_OwnerPackage;
	}
	unsigned long Asset::GetSizeInBytes() const
	{
		return m_Definition.GetSize();
	}
	Guid Asset::GetID() const
	{
		return m_Definition.GetID();
	}
	bool Asset::IsLoaded() const
	{
		return m_LoadedObject != nullptr;
	}
	bool Asset::IsRawFile() const
	{
		return m_bTargetsRawFile;
	}
	Asset::~Asset()
	{
		/*
		* Destory if its not destroyed
		*/
		if (!m_LoadedObject->IsDestroyed())
			m_LoadedObject->Destroy();

		/*
		* Delete heap object
		*/
		delete m_LoadedObject;

		m_LoadedObject = nullptr;
		m_OwnerPackage = nullptr;
	}
}