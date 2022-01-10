#include "Asset.h"
#include <Rudy/Platform/Utility/PlatformFile.h>

namespace Rudy
{
	Asset::Asset(const AssetDefinition& definition)
	{
		m_LoadedObject = nullptr;
		m_Definition = definition;
	}
	void Asset::Load()
	{
		/*
		* Validate if its loaded
		*/
		if (m_LoadedObject != nullptr)
			return;

		/*
		* Load the asset bytes
		*/
		Array<unsigned char> assetBytes;
		PlatformFile::Read(m_Definition.GetSourceAbsolutePath(), m_Definition.GetOffset(), m_Definition.GetOffset() + m_Definition.GetSize(), assetBytes);

		/*
		* Catch asset type and create asset
		*/
		AssetType type = m_Definition.GetType();
		RudyObject* loadedObject = nullptr;
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

		/*
		* Set loaded object
		*/
		m_LoadedObject = loadedObject;
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
		m_LoadedObject->Destroy();
		delete m_LoadedObject;
		m_LoadedObject = nullptr;
	}
	RudyObject* Asset::GetLoadedObject() const
	{
		return m_LoadedObject;
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
	}
}