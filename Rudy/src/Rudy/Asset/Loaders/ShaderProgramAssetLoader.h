#pragma once
#include <Rudy/Asset/Loaders/IAssetLoader.h>

namespace Rudy
{
	class RUDY_API ShaderProgramAssetLoader : public IAssetLoader
	{
	public:
		ShaderProgramAssetLoader(ApplicationSession* session);
		~ShaderProgramAssetLoader() = default;

		// Inherited via IAssetResolver
		virtual AssetObject* Load(const ByteBlock& assetContentBytes) override;
	};
}