#pragma once
#include <Bite/Domain/Assets/IAssetWriter.h>
#include <Rudy/Memory/String.h>

namespace Rudy
{
	class Shader;
}
namespace Bite
{
	struct ShaderProgramWriteParameters
	{
		ShaderProgramWriteParameters(const Rudy::String& programName,const Rudy::String& programCategory,const Rudy::Array<Rudy::Shader*> shaders) :
			ProgramName(programName),ProgramCategory(programCategory),Shaders(shaders) {}
		Rudy::String ProgramName;
		Rudy::String ProgramCategory;
		Rudy::Array<Rudy::Shader*> Shaders;
	};

	class BITE_API ShaderProgramAssetWriter : public IAssetWriter
	{
	public:
		ShaderProgramAssetWriter(Rudy::ApplicationSession* session);
		~ShaderProgramAssetWriter() = default;


		// Inherited via IAssetWriter
		virtual void Write(const void* parameters, Rudy::ByteBlock& destinationBytes) override;

	};


}