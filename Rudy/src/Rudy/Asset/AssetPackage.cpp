#include "AssetPackage.h"
#include <Rudy/Asset/AssetDefinition.h>
#include <Rudy/Asset/Asset.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Asset/AssetUtilities.h>
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
		ByteBlock byteBlock;
		PlatformFile::Read(packagePath, 0, 4, byteBlock);
		const unsigned int definitionCount = byteBlock.To<unsigned int>();

		/*
		* Iterate and gather all definitions
		*/
		unsigned int byteStart = 4;
		while (byteStart < totalFileSize)
		{
			/*
			* Get defintion block
			*/
			ByteBlock byteBlock;
			PlatformFile::Read(packagePath,
				byteStart, byteStart + definitionBytes,
				byteBlock);

			/*
			* Create definition
			*/
			ByteBlock typeBytes(byteBlock, 0, 4);
			ByteBlock idBytes(byteBlock, 4, 20);
			ByteBlock nameBytes(byteBlock, 20, 40);
			ByteBlock offsetBytes(byteBlock, 40, 44);
			ByteBlock sizeBytes(byteBlock, 44, 48);

			AssetType assetType = typeBytes.To<AssetType>();
			String name((char*)nameBytes.GetBlock(), nameBytes.GetBlockSize());
			Guid id = idBytes.To<Guid>();
			unsigned long offset = offsetBytes.To<unsigned long>();
			unsigned long size = sizeBytes.To<unsigned long>();
			AssetDefinition definition(packagePath,assetType,id,name,offset,size);

			/*
			* Register definition
			*/
			m_Definitions.Add(definition);

			/*
			* Register asset
			*/
			m_Assets.Add(new Asset(definition,this,false));

			/*
			* Increment byteStart
			*/
			byteStart += definitionBytes;
		}

		/*
		* Set virtual state
		*/
		m_bVirtual = false;
	}
	AssetPackage::AssetPackage()
	{
		m_PackageID = Guid::Create();
		m_PackagePath = "Virtual Path";
		m_bVirtual = true;
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
	Asset* AssetPackage::RegisterVirtualAsset(const String& assetPath,bool bTargetsRawFile)
	{
		Asset* asset = nullptr;
		if (bTargetsRawFile)
		{
			/*
			* Create asset definiton
			*/
			AssetType assetType = AssetUtilities::GetAssetTypeViaExtension(assetPath);
			String name = PlatformFile::GetFileNameFromPath(assetPath);
			Guid id = Guid::Create();
			unsigned long offset = 0;
			unsigned long size = 0;
			PlatformFile::GetFileLength(assetPath, size);
			AssetDefinition definition(assetPath, assetType, id, name, offset, size);

			/*
			* Create asset
			*/
			asset = new Asset(definition, this, true);

			/*
			* Register asset and definition
			*/
			m_Assets.Add(asset);
			m_Definitions.Add(definition);
		}
		else
		{
			/*
			* Load asset file definition bytes
			*/
			ByteBlock defintionBlockBytes;
			PlatformFile::Read(assetPath, 0, 48u, defintionBlockBytes);

			/*
			* Slice asset definition bytes
			*/
			ByteBlock typeBytes(defintionBlockBytes, 0, 4);
			ByteBlock idBytes(defintionBlockBytes, 4, 20);
			ByteBlock nameBytes(defintionBlockBytes, 20, 40);
			ByteBlock offsetBytes(defintionBlockBytes, 40, 44);
			ByteBlock sizeBytes(defintionBlockBytes, 44, 48);

			/*
			* Create asset definiton
			*/
			AssetType assetType = typeBytes.To<AssetType>();
			String name((char*)nameBytes.GetBlock(), nameBytes.GetBlockSize());
			Guid id = idBytes.To<Guid>();
			unsigned long offset = offsetBytes.To<unsigned long>();
			unsigned long size = sizeBytes.To<unsigned long>();
			AssetDefinition definition(assetPath, assetType, id, name, offset, size);

			/*
			* Create asset
			*/
			asset = new Asset(definition, this, false);

			/*
			* Register asset and definition
			*/
			m_Assets.Add(asset);
			m_Definitions.Add(definition);
		}
		

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
	Asset* AssetPackage::GetAsset(const Guid& id)
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
				return m_Assets[i];
			}
		}

		return nullptr;
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