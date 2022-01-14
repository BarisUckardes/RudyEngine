#include "DomainAssetView.h"
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Memory/ByteBlock.h>
namespace Bite
{
	DomainAssetView::DomainAssetView(const Rudy::String& absoluteAssetPath)
	{
		/*
		* Load asset file header
		*/
		Rudy::ByteBlock defintionByteBlock;
		Rudy::PlatformFile::Read(absoluteAssetPath,0u,48u,defintionByteBlock);

		/*
		* Create defintion variables
		*/
		Rudy::AssetType assetType = defintionByteBlock.To<Rudy::AssetType>(0);
		Rudy::Guid assetID = defintionByteBlock.To<Rudy::Guid>(4);
		Rudy::String assetName((char*)((defintionByteBlock.GetBlock() + 20), 20));
		unsigned long offset = defintionByteBlock.To<unsigned long>(40);
		unsigned long size = defintionByteBlock.To<unsigned long>(44);
		Rudy::AssetDefinition definition("", assetType, assetID, assetName, offset, size);

		/*
		* Set properties
		*/
		m_Definition = definition;
		m_AbsolutePath = absoluteAssetPath;
		
	}
}