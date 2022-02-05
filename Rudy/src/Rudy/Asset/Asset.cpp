#include "Asset.h"
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Graphics/Texture/Texture2D.h>
#include <Rudy/Graphics/Shader/Shader.h>
#include <Rudy/Graphics/Shader/ShaderProgram.h>
#include <Rudy/Asset/AssetPackage.h>
#include <Rudy/Asset/AssetPool.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <stdio.h>
#include <Rudy/Core/Log.h>
#include <Rudy/Asset/AssetWriteConstants.h>
#include <Rudy/Asset/Loaders/AssetLoaders.h>
namespace Rudy
{
	Asset::Asset(const AssetHeaderContainer& header,const String& assetAbsolutePath,AssetPackage* ownerPackage,bool bTargetsRawFile)
	{
		m_LoadedObject = nullptr;
		m_OwnerPackage = ownerPackage;
		m_Header = header;
		m_bTargetsRawFile = bTargetsRawFile;
		m_AbsolutePath = assetAbsolutePath;
	}
	bool Asset::HasCache() const
	{
		return m_bHasCache;
	}
	void Asset::Load(ApplicationSession* session,bool bCacheLoadedData)
	{
		/*
		* Validate if its loaded
		*/
		if (m_LoadedObject != nullptr)
			return;

		/*
		* Catch asset type and create asset
		*/
		AssetType type = m_Header.Type;
		RudyObject* loadedObject = nullptr;
		
		if (m_bTargetsRawFile)
		{
			switch (type)
			{
				case Rudy::AssetType::Undefined:
					break;
				case Rudy::AssetType::Texture1D:
					break;
				case Rudy::AssetType::Texture2D:
				{
					/*
					* Load texture into memory
					*/
					Texture2DDiskLoadResult* result = Texture2D::LoadToMemoryFromDisk(m_AbsolutePath);

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
					texture->SetTextureData(result->DataBlock.GetBlock(), result->DataBlock.GetBlockSize());

					loadedObject = (RudyObject*)texture;
					break;
				}
				case Rudy::AssetType::Texture3D:
					break;
				case Rudy::AssetType::CubeTexture:
					break;
				case Rudy::AssetType::Mesh:
					break;
				default:
					break;
			}
		}
		else
		{
			/*
			* Create asset content bytes byte block
			*/
			Rudy::ByteBlock assetContentBytes;

			/*
			* Validate cahce
			*/
			if (m_bHasCache)
			{
				/*
				* Load cached data here
				*/
				LOG("This asset has cache, loading from the cache");
			}
			else
			{
				LOG("No cache found for this asset, loading from the disk");
				/*
				* Read from the disk
				*/
				PlatformFile::Read(m_AbsolutePath,
					m_Header.Offset, m_Header.Offset + m_Header.Size,
					assetContentBytes);
				/*
				* Cache the data if its requested
				*/
				if (bCacheLoadedData)
				{
					m_CachedData = ByteBlock(assetContentBytes);
				}
			}
			

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
				{
					/*
					* Create shader asset loader
					*/
					ShaderAssetLoader loader(session);

					/*
					* Set loaded object as shader
					*/
					loadedObject = loader.Load(assetContentBytes);
					break;
				}
				case Rudy::AssetType::ShaderProgram:
				{
					/*
					* Create shader program asset resolver
					*/
					ShaderAssetLoader loader(session);

					/*
					* Set loaded object as shader program
					*/
					loadedObject = loader.Load(assetContentBytes);
					break;
				}
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
		m_bHasCache = true;
	}
	void Asset::DeleteCache()
	{
		m_bHasCache = false;
	}
	void Asset::Unload()
	{
		/*
		* Validate if its not loaded
		*/
		if (m_LoadedObject == nullptr)
			return;

		/*
		* Destroy object and its contents
		*/
		if (!m_LoadedObject->IsDestroyed())
		{
			m_LoadedObject->Destroy();
		}

		LOG("DELETED asset ID : %s", m_Header.ID.GetAsString());

		/*
		* Delete heap object
		*/
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
	AssetHeaderContainer Asset::GetAssetHeader() const
	{
		return m_Header;
	}
	unsigned long Asset::GetSizeInBytes() const
	{
		return m_Header.Size;
	}
	Guid Asset::GetID() const
	{
		return m_Header.ID;
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