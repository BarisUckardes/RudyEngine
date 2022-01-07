#include "AssetPackage.h"
#include <Rudy/Asset/AssetDefinition.h>
#include <Rudy/Asset/Asset.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <stdio.h>
namespace Rudy
{
	AssetPackage::AssetPackage(const String& packagePath)
	{
		printf("PACKAGE READ START...\n");
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
		printf("	Found definition count: %d\n", definitionCount);

		/*
		* Iterate and gather all definitions
		*/
		unsigned int byteStart = 4;
		while (byteStart < totalFileSize)
		{
			printf("		Reading %d-%d\n", byteStart,byteStart+definitionBytes);
			/*
			* Get defintion block
			*/
			Array<unsigned char> defintionBlockBytes;
			PlatformFile::Read(packagePath, byteStart, byteStart + definitionBytes, defintionBlockBytes);

			/*
			* Create definition
			*/
			AssetDefinition definition = *(AssetDefinition*)defintionBlockBytes.GetData();
			printf("		Definition asset type: %d\n", definition.GetType());

			/*
			* Register definition
			*/
			m_Definitions.Add(definition);

			/*
			* Increment byteStart
			*/
			byteStart += definitionBytes;
		}
		printf("PACKAGE READ END!\n");
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