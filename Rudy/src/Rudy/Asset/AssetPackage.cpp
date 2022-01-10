#include "AssetPackage.h"
#include <Rudy/Asset/AssetDefinition.h>
#include <Rudy/Asset/Asset.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <stdio.h>
namespace Rudy
{
	AssetPackage::AssetPackage(const String& packagePath)
	{
		constexpr unsigned int definitionBytes = 48u;
		/*
		* Get total file size
		*/
		unsigned long totalFileSize = 0;
		PlatformFile::GetFileLength(packagePath, totalFileSize);

		/*
		* Get how many definitions this package has
		*/
		Array<unsigned char> definitionCountBytes;
		PlatformFile::Read(packagePath, 0, 4, definitionCountBytes);
		const unsigned int definitionCount = *(unsigned int*)definitionCountBytes.GetData();

		/*
		* Iterate and gather all definitions
		*/
		unsigned int byteStart = 4;
		while (byteStart < totalFileSize)
		{
			/*
			* Get defintion block
			*/
			Array<unsigned char> defintionBlockBytes;
			PlatformFile::Read(packagePath, byteStart, byteStart + definitionBytes, defintionBlockBytes);

			/*
			* Create definition
			*/
			Array<unsigned char> typeBytes = defintionBlockBytes.GetSlice(0,4);
			Array<unsigned char> idBytes = defintionBlockBytes.GetSlice(4, 20);
			Array<unsigned char> nameBytes = defintionBlockBytes.GetSlice(20, 40);
			Array<unsigned char> offsetBytes = defintionBlockBytes.GetSlice(40, 44);
			Array<unsigned char> sizeBytes = defintionBlockBytes.GetSlice(44, 48);

			AssetType assetType = *(AssetType*)typeBytes.GetData();
			String name((char*)nameBytes.GetData(), nameBytes.GetCursor());
			Guid id = *(Guid*)idBytes.GetData();
			unsigned long offset = *(unsigned long*)offsetBytes.GetData();
			unsigned long size = *(unsigned long*)sizeBytes.GetData();
			AssetDefinition definition(packagePath,assetType,id,name,offset,size);

			/*
			* Register definition
			*/
			m_Definitions.Add(definition);

			/*
			* Register asset
			*/
			m_Assets.Add(new Asset(definition));

			/*
			* Increment byteStart
			*/
			byteStart += definitionBytes;
		}
	}
	AssetPackage::AssetPackage()
	{
		m_PackageID = Guid::Create();
		m_PackagePath = "Virtual Path";
	}
	AssetPackage::~AssetPackage()
	{
		/*
		* Unload package
		*/
		UnloadPackage();

		/*
		* Clear
		*/
		m_Definitions.Clear();
		m_Assets.Clear();
	}
	Asset* AssetPackage::RegisterVirtualAsset(const String& path)
	{
		/*
		* Load asset file definition bytes
		*/
		Array<unsigned char> defintionBlockBytes;
		PlatformFile::Read(path, 0, 48u, defintionBlockBytes);

		/*
		* Slice asset definition bytes
		*/
		Array<unsigned char> typeBytes = defintionBlockBytes.GetSlice(0, 4);
		Array<unsigned char> idBytes = defintionBlockBytes.GetSlice(4, 20);
		Array<unsigned char> nameBytes = defintionBlockBytes.GetSlice(20, 40);
		Array<unsigned char> offsetBytes = defintionBlockBytes.GetSlice(40, 44);
		Array<unsigned char> sizeBytes = defintionBlockBytes.GetSlice(44, 48);

		/*
		* Create asset definiton
		*/
		AssetType assetType = *(AssetType*)typeBytes.GetData();
		String name((char*)nameBytes.GetData(), nameBytes.GetCursor());
		Guid id = *(Guid*)idBytes.GetData();
		unsigned long offset = *(unsigned long*)offsetBytes.GetData();
		unsigned long size = *(unsigned long*)sizeBytes.GetData();
		AssetDefinition definition(path,assetType, id, name, offset, size);

		/*
		* Create asset
		*/
		Asset* asset = new Asset(definition);

		/*
		* Register asset and definition
		*/
		m_Assets.Add(asset);
		m_Definitions.Add(definition);

		return asset;
	}
	bool AssetPackage::RemoveVirtualAsset(const Guid& id)
	{
		/*
		* Iterate and validate
		*/
		for (int i = 0; i < m_Definitions.GetCursor(); i++)
		{
			/*
			* Get definition
			*/
			const AssetDefinition& definition = m_Definitions[i];

			/*
			* Validate guid
			*/
			if (definition.GetID() == id)
			{
				m_Assets[i]->Unload();
				delete m_Assets[i];
				m_Assets.RemoveIndex(i);
				m_Definitions.RemoveIndex(i);
				return true;
			}
		}
		return false;
	}
	const Asset* AssetPackage::LoadAsset(const Guid& id)
	{
		/*
		* Iterate and validate
		*/
		for (int i = 0; i < m_Definitions.GetCursor(); i++)
		{
			/*
			* Get definition
			*/
			const AssetDefinition& definition = m_Definitions[i];

			/*
			* Validate guid
			*/
			if (definition.GetID() == id)
			{
				m_Assets[i]->Load();
				return m_Assets[i];
			}
		}

		return nullptr;
	}
	void AssetPackage::UnloadAsset(const Guid& id)
	{
		/*
		* Iterate and validate
		*/
		for (int i = 0; i < m_Assets.GetCursor(); i++)
		{
			/*
			* Get asset
			*/
			Asset* asset = m_Assets[i];

			/*
			* Validate
			*/
			if (asset->GetID() == id)
			{
				/*
				* Unload the asset
				*/
				asset->Unload();
				return;
			}
		}
	}
	void AssetPackage::UnloadPackage()
	{
		/*
		* Iterate and unload all assets
		*/
		for (int i = 0; i < m_Assets.GetCursor(); i++)
		{
			/*
			* Get asset
			*/
			Asset* asset = m_Assets[i];

			/*
			* Unload the asset
			*/
			asset->Unload();
		}
	}
	AssetDefinition AssetPackage::GetDefiniton(const Guid& id)
	{
		/*
		* Iterate and validate
		*/
		for (int i = 0; i < m_Definitions.GetCursor(); i++)
		{
			/*
			* Get defintion
			*/
			const AssetDefinition& defintion = m_Definitions[i];

			/*
			* Validate
			*/
			if (defintion.GetID() == id)
			{
				return defintion;
			}
		}

		return AssetDefinition();
	}
	Guid AssetPackage::GetPackageID() const
	{
		return m_PackageID;
	}
	unsigned long AssetPackage::GetTotalAssetSize() const
	{
		unsigned long totalSize = 0;

		/*
		* Iterate and gather total asset size
		*/
		for (int i = 0; i < m_Definitions.GetCursor(); i++)
		{
			/*
			* Get asset
			*/
			const AssetDefinition& definition = m_Definitions[i];

			/*
			* Get and increment
			*/
			totalSize += definition.GetSize();
		}

		return totalSize;
	}
	unsigned long AssetPackage::GetAllocatedAssetSize() const
	{
		unsigned long allocatedSize = 0;

		/*
		* Iterate and gather total asset size
		*/
		for (int i = 0; i < m_Assets.GetCursor(); i++)
		{
			/*
			* Get asset
			*/
			Asset* asset = m_Assets[i];

			/*
			* Get and increment
			*/
			allocatedSize += asset->GetSizeInBytes() * (asset->IsLoaded() ? 1.0f : 0.0f);
		}

		return allocatedSize;
	}
	bool AssetPackage::IsVirtual() const
	{
		return m_bVirtual;
	}
	Array<AssetDefinition> AssetPackage::GetDefinitions() const
	{
		return m_Definitions;
	}
}