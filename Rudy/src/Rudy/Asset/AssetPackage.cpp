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
			AssetDefinition definition(assetType,id,name,offset,size);

			/*
			* Register definition
			*/
			m_Definitions.Add(definition);

			/*
			* Increment byteStart
			*/
			byteStart += definitionBytes;
		}
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
		m_LoadedAssets.Clear();
	}
	const Asset* AssetPackage::LoadAsset(const Guid& id)
	{
		/*
		* Iterate and check loaded assets
		*/
		for (int i = 0; i < m_LoadedAssets.GetCursor(); i++)
		{
			/*
			* Get asset
			*/
			const Asset* asset = m_LoadedAssets[i];

			/*
			* Validate
			*/
			if (asset->GetID() == id)
			{
				return asset;
			}
		}

		/*
		* Iterrate and validate
		*/
		for (int i = 0; i <m_Definitions.GetCursor(); i++)
		{
			/*
			* Get asset definition
			*/
			const AssetDefinition& defintion = m_Definitions[i];

			/*
			* Validate
			*/
			if (defintion.GetID() == id)
			{
				/*
				* Load
				*/
				const unsigned int assetByteOffset = defintion.GetOffset();
				const unsigned int assetSizeInBytes = defintion.GetSize();

				/*
				* Read bytes
				*/
				Array<unsigned char> bytesRead;
				PlatformFile::Read(m_PackagePath, assetByteOffset, assetByteOffset + assetSizeInBytes, bytesRead);

				/*
				* Convert bytes to appropiate asset containers
				*/

				/*
				* Create new asset
				*/
				Asset* asset = nullptr;

				/*
				* Register asset
				*/
				return asset;
			}
		}

		return nullptr;
	}
	void AssetPackage::UnloadAsset(const Guid& id)
	{
		/*
		* Iterate and validate
		*/
		for (int i = 0; i < m_LoadedAssets.GetCursor(); i++)
		{
			/*
			* Get asset
			*/
			Asset* asset = m_LoadedAssets[i];

			/*
			* Validate
			*/
			if (asset->GetID() == id)
			{
				/*
				* Delete asset
				*/
				delete asset;

				/*
				* Remove it from the loaded assets
				*/
				m_LoadedAssets.RemoveIndex(i);

				return;
			}
		}
	}
	void AssetPackage::UnloadPackage()
	{
		/*
		* Iterate and unload all assets
		*/
		for (int i = 0; i < m_LoadedAssets.GetCursor(); i++)
		{
			/*
			* Get asset
			*/
			Asset* asset = m_LoadedAssets[i];

			/*
			* Delete asset
			*/
			delete asset;
		}
		m_LoadedAssets.Clear();
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
	Array<AssetDefinition> AssetPackage::GetDefinitions() const
	{
		return m_Definitions;
	}
}