#include "AssetHeaderGenerator.h"
#include <stdio.h>

namespace Rudy
{
    Rudy::ByteBlock AssetHeaderGenerator::GenerateByteBlock(const AssetHeaderContainer& header)
    {
        return Rudy::ByteBlock((void*)&header, sizeof(AssetHeaderContainer));
    }

    AssetHeaderContainer AssetHeaderGenerator::GenerateHeader(const Rudy::ByteBlock& block)
    {
        AssetHeaderContainer header;

        /*
        * Get assetType
        */
        const AssetType assetType = block.To<AssetType>(0);

        /*
        * Get asset id
        */
        const Guid id = block.To<Guid>(4);


        /*
        * Get chars
        */
        Byte* namePtr = block.GetAdress(20);
        Memory::MemoryCopy(&header.Name, namePtr, 20);
       
        /*
        * Get offset
        */
        const unsigned long offset = block.To<unsigned long>(40);

        /*
        * Get size
        */
        const unsigned long size = block.To<unsigned long>(44);

        /*
        * Generate header
        */
        header.Type = assetType;
        header.ID = id;
        header.Offset = offset;
        header.Size = size;
        return header;
    }

}