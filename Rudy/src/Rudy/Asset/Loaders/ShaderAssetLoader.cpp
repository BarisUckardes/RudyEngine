#include "ShaderAssetLoader.h"
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Graphics/Shader/Shader.h>
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
namespace Rudy
{
	ShaderAssetLoader::ShaderAssetLoader(ApplicationSession* session) : IAssetLoader(session)
	{
		
	}
	RudyObject* ShaderAssetLoader::Load(const ByteBlock& assetContentBytes)
	{
		/*
		* Get shader stage type
		*/
		const ShaderStage stage = assetContentBytes.To<ShaderStage>(0);
		LOG("Shader stage : %d", stage);

		/*
		* Calculate the length of the shader source
		*/
		const unsigned long shaderSourceLength = assetContentBytes.GetBlockSize() - 4u + 1u; // TODO: something sketchy about the byte strides

		/*
		* Get shader stage source
		*/
		const String sourceText((char*)assetContentBytes.GetAdress(0) + 4, shaderSourceLength);
		LOG("Shader source text: %s", *sourceText);

		/*
		* Create a shader
		*/
		Shader* shader = GetSession()->GetDefaultGraphicsDevice()->CreateShader(stage);

		/*
		* Compile shader
		*/
		shader->Compile(sourceText);

		return (RudyObject*)shader;
	}

}