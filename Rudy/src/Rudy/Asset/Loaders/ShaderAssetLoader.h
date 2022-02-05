#pragma once
#include <Rudy/Asset/Loaders/IAssetLoader.h>

namespace Rudy
{
	/// <summary>
	/// Asset resolver implementation for Shader object
	/// </summary>
	class RUDY_API ShaderAssetLoader : public IAssetLoader
	{
	public:
		ShaderAssetLoader(ApplicationSession* session);
		~ShaderAssetLoader() = default;

		// Inherited via IAssetResolver
		virtual AssetObject* Load(const ByteBlock& assetContentBytes) override;
	};


}