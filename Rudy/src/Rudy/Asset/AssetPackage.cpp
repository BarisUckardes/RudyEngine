#include "AssetPackage.h"
#include <Rudy/Asset/AssetDefinition.h>
#include <Rudy/Asset/Asset.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Asset/AssetUtilities.h>
#include <stdio.h>
#include <Rudy/Asset/Containers/AssetHeaderContainer.h>
#include <Rudy/Asset/AssetHeaderGenerator.h>
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
			* Create header
			*/
			ByteBlock headerBytes(byteBlock, 0, 48);
			AssetHeaderContainer header = AssetHeaderGenerator::GenerateHeader(headerBytes);

			/*
			* Register header
			*/
			m_Headers.Add(AssetHeaderGenerator::GenerateHeader(headerBytes));

			/*
			* Register asset
			*/
			m_Assets.Add(new Asset(header,"PackagePath", this, false));

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
		m_Headers.Clear();
		m_Assets.Clear();
	}
	Asset* AssetPackage::RegisterVirtualAsset(const String& assetPath,bool bTargetsRawFile)
	{
		Asset* asset = nullptr;
		if (bTargetsRawFile)
		{
			/*
			* Get asset properties
			*/
			AssetType assetType = AssetUtilities::GetAssetTypeViaExtension(assetPath);
			String name = PlatformFile::GetFileNameFromPath(assetPath);
			Guid id = Guid::Create();
			unsigned long offset = 0;
			unsigned long size = 0;
			PlatformFile::GetFileLength(assetPath, size);

			/*
			* Generate asset header
			*/
			AssetHeaderContainer header;
			header.Type = assetType;
			header.ID = id;
			Memory::MemoryCopy(&header.Name, (void*)*name, name.GetCursor());
			header.Offset = offset;
			header.Size = size;

			/*
			* Create asset
			*/
			asset = new Asset(header,assetPath, this, true);

			/*
			* Register asset and definition
			*/
			m_Assets.Add(asset);
			m_Headers.Add(header);
		}
		else
		{
			/*
			* Load asset file definition bytes
			*/
			ByteBlock defintionBlockBytes;
			PlatformFile::Read(assetPath, 0, sizeof(AssetHeaderContainer), defintionBlockBytes);

			/*
			* Generate to asset
			*/
			AssetHeaderContainer header = AssetHeaderGenerator::GenerateHeader(defintionBlockBytes);

			/*
			* Create asset
			*/
			asset = new Asset(header,assetPath,this,false);

			/*
			* Register header
			*/
			m_Headers.Add(header);
		}
		

		return asset;
	}
	bool AssetPackage::RemoveVirtualAsset(const Guid& id)
	{
		/*
		* Iterate and validate
		*/
		for (int i = 0; i < m_Headers.GetCursor(); i++)
		{
			/*
			* Get header
			*/
			const AssetHeaderContainer& header = m_Headers[i];

			/*
			* Validate guid
			*/
			if (header.ID == id)
			{
				m_Assets[i]->Unload();
				delete m_Assets[i];
				m_Assets.RemoveIndex(i);
				m_Headers.RemoveIndex(i);
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
		for (int i = 0; i < m_Headers.GetCursor(); i++)
		{
			/*
			* Get header
			*/
			const AssetHeaderContainer& header = m_Headers[i];

			/*
			* Validate guid
			*/
			if (header.ID == id)
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
	AssetHeaderContainer AssetPackage::GetHeader(const Guid& id)
	{
		/*
		* Iterate and validate
		*/
		for (int i = 0; i < m_Headers.GetCursor(); i++)
		{
			/*
			* Get header
			*/
			const AssetHeaderContainer& header = m_Headers[i];

			/*
			* Validate
			*/
			if (header.ID == id)
			{
				return header;
			}
		}

		return AssetHeaderContainer();
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
		for (int i = 0; i < m_Headers.GetCursor(); i++)
		{
			/*
			* Get asset
			*/
			const AssetHeaderContainer& header = m_Headers[i];

			/*
			* Get and increment
			*/
			totalSize += header.Size;
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
	Array<AssetHeaderContainer> AssetPackage::GetHeaders() const
	{
		return m_Headers;
	}
}