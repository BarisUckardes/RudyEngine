#include "ShaderProgramAssetWriter.h"
#include <Rudy/Asset/AssetWriteConstants.h>
#include <Rudy/Memory/Memory.h>
#include <Rudy/Memory/ByteBlock.h>
namespace Bite
{
    ShaderProgramAssetWriter::ShaderProgramAssetWriter(Rudy::ApplicationSession* session) : IAssetWriter(session)
    {

    }
    void ShaderProgramAssetWriter::Write(const void* parameters, Rudy::ByteBlock& destinationBytes)
    {
		/*
		* Get parameters
		*/
		const ShaderProgramWriteParameters& writeParameters = *(const ShaderProgramWriteParameters*)parameters;

		/*
		* Write
		*/
		const unsigned long assetSize = ASSET_WRITE_MAX_NAME + ASSET_WRITE_MAX_NAME + 4u + writeParameters.Shaders.GetCursor() * sizeof(unsigned char*);
		Byte* assetContentBuffer = new Byte[assetSize];
		Rudy::Memory::MemoryCopy(assetContentBuffer + 4, (char*)*writeParameters.ProgramName, ASSET_WRITE_MAX_NAME);
		Rudy::Memory::MemoryCopy((assetContentBuffer + 4 + ASSET_WRITE_MAX_NAME), (char*)*writeParameters.ProgramCategory, ASSET_WRITE_MAX_NAME);
		Rudy::Memory::MemoryCopy(assetContentBuffer, (void*) & writeParameters, sizeof(unsigned long));
		destinationBytes = Rudy::ByteBlock(assetContentBuffer, assetSize);
    }
}