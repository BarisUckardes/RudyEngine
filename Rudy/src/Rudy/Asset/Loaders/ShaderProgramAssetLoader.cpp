#include "ShaderProgramAssetLoader.h"
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Graphics/Shader/ShaderProgram.h>
#include <Rudy/Memory/Guid.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Asset/AssetWriteConstants.h>
namespace Rudy
{
	ShaderProgramAssetLoader::ShaderProgramAssetLoader(ApplicationSession* session) : IAssetLoader(session)
	{

	}
	RudyObject* ShaderProgramAssetLoader::Load(const ByteBlock& assetContentBytes)
	{
		/*
		* Get shader program shader count
		*/
		const unsigned int shaderCount = assetContentBytes.To<unsigned int>(0);

		/*
		* Get shader program name
		*/
		const String programName((char*)assetContentBytes.GetAdress(0) + 4, ASSET_WRITE_MAX_NAME);

		/*
		* Get shader program category
		*/
		const String programCategory((char*)assetContentBytes.GetAdress(0) + ASSET_WRITE_MAX_NAME + 4, ASSET_WRITE_MAX_NAME);

		/*
		* Iterate and convert shader guids
		*/
		const unsigned int shadersOffset = 4u + ASSET_WRITE_MAX_NAME + ASSET_WRITE_MAX_NAME;
		Array<Shader*> programShaders;
		for (unsigned int i = 0; i < shaderCount; i++)
		{
			/*
			* Get shader guid
			*/
			const Guid shaderID = assetContentBytes.To<Guid>(shadersOffset + i * sizeof(Guid));

			/*
			* Load shader via asset pool
			*/
			Shader* loadedShader = nullptr;

			/*
			* Register shader into list
			*/
			programShaders.Add(loadedShader);
		}

		/*
		* Create shader program
		*/
		ShaderProgram* program = GetSession()->GetDefaultGraphicsDevice()->CreateShaderProgram();
		/*program->SetProgramName(programName);
		program->SetProgramCategory(programCategory);
		program->LinkProgram(programShaders);*/

		return (RudyObject*)program;
	}
}