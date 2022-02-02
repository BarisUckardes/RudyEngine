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
		AssetType type = m_Header.Type;
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
			Rudy::ByteBlock assetContentBytes;

			/*
			* Validate cahce
			*/
			if (m_bHasCache)
			{
				/*
				* Load cached data here
				*/
			}
			else
			{
				PlatformFile::Read(m_AbsolutePath,
					m_Header.Offset, m_Header.Offset + m_Header.Size,
					assetContentBytes);
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
					* Get shader stage type
					*/
					const ShaderStage stage = assetContentBytes.To<ShaderStage>(0);

					/*
					* Calculate the length of the shader source
					*/
					const unsigned long shaderSourceLength = assetContentBytes.GetBlockSize() - 4u + 1u; // TODO: something sketchy about the byte strides

					/*
					* Get shader stage source
					*/
					const String sourceText((char*)assetContentBytes.GetAdress(0)+4,shaderSourceLength);
					/*
					* Create a shader
					*/
					Shader* shader = session->GetDefaultGraphicsDevice()->CreateShader(stage);

					/*
					* Compile shader
					*/
					shader->Compile(sourceText);

					/*
					* Set loaded object as shader
					*/
					loadedObject = (RudyObject*)shader;
					break;
				}
				case Rudy::AssetType::ShaderProgram:
				{
					/*
					* Get shader program shader count
					*/
					const unsigned int shaderCount = assetContentBytes.To<unsigned int>(0);

					/*
					* Get shader program name
					*/
					const String programName((char*)assetContentBytes.GetAdress(0) + 4, ASSET_WRITE_MAX_NAME);

					/*
					* Get shader program category
					*/
					const String programCategory((char*)assetContentBytes.GetAdress(0) + ASSET_WRITE_MAX_NAME + 4, ASSET_WRITE_MAX_NAME);

					/*
					* Iterate and convert shader guids
					*/
					const unsigned int shadersOffset = 4u + ASSET_WRITE_MAX_NAME + ASSET_WRITE_MAX_NAME;
					Array<Shader*> programShaders;
					for (unsigned int i = 0; i < shaderCount; i++)
					{
						/*
						* Get shader guid
						*/
						const Guid shaderID = assetContentBytes.To<Guid>(shadersOffset + i * sizeof(Guid));

						/*
						* Load shader via asset pool
						*/
						Shader* loadedShader = nullptr;

						/*
						* Register shader into list
						*/
						programShaders.Add(loadedShader);
					}

					/*
					* Create shader program
					*/
					ShaderProgram* program = session->GetDefaultGraphicsDevice()->CreateShaderProgram();
					/*program->SetProgramName(programName);
					program->SetProgramCategory(programCategory);
					program->LinkProgram(programShaders);*/


					/*
					* Set loaded object as shader program
					*/
					loadedObject = (RudyObject*)program;
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