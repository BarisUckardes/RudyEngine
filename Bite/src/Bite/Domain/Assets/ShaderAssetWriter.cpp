#include "ShaderAssetWriter.h"
#include <Rudy/Graphics/Shader/Shader.h>
#include <Rudy/Asset/Containers/AssetHeaderContainer.h>
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Asset/AssetHeaderGenerator.h>
#include <Rudy/Core/Log.h>
namespace Bite
{
	ShaderAssetWriter::ShaderAssetWriter(Rudy::ApplicationSession* session) : IAssetWriter(session)
	{
	}

    void ShaderAssetWriter::Write(const void* parameters, Rudy::ByteBlock& destinationBytes)
    {
		/*
		* Get shader write parameters
		*/
		const ShaderWriteParameters& writeParameters = *(ShaderWriteParameters*)parameters;

		/*
		* Get requested shader stage
		*/
		Rudy::ShaderStage stage = writeParameters.Stage;

		/*
		* Generate new shader container
		*/
		Rudy::String sourceText = writeParameters.SourceText;

		/*
		* Generate shader content bytes
		*/
		Byte* assetContentBuffer = new Byte[4 + sourceText.GetCursor()];
		Rudy::Memory::MemoryCopy(assetContentBuffer, &stage, 4);
		Rudy::Memory::MemoryCopy((assetContentBuffer + 4), (char*)*sourceText, sourceText.GetCursor());

		/*
		* Set destination bytes
		*/
		destinationBytes = Rudy::ByteBlock(assetContentBuffer, 4 + sourceText.GetCursor());

		/*
		* Free allocated resources
		*/
		delete[] assetContentBuffer;
    }
	
}