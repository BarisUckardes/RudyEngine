#pragma once
#include <Bite/Domain/Assets/IAssetWriter.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Graphics/Shader/ShaderStage.h>
namespace Bite
{
	struct ShaderWriteParameters
	{
		ShaderWriteParameters(Rudy::ShaderStage stage, const Rudy::String& sourceText) : Stage(stage), SourceText(sourceText) {}
		Rudy::ShaderStage Stage;
		Rudy::String SourceText;
	};

	class BITE_API ShaderAssetWriter : public IAssetWriter
	{
	public:
		ShaderAssetWriter(Rudy::ApplicationSession* session);
		~ShaderAssetWriter() = default;


		// Inherited via IAssetWriter
		virtual void Write(const void* parameters, Rudy::ByteBlock& destinationBytes) override;

	};

}
