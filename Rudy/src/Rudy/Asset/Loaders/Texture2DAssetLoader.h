#pragma once
#include <Rudy/Asset/Loaders/IAssetLoader.h>

namespace Rudy
{
	/// <summary>
	/// Asset resolver implementation for a Texture2D object
	/// </summary>
	class RUDY_API Texture2DAssetLoader : public IAssetLoader
	{
	public:
		Texture2DAssetLoader(ApplicationSession* sesion);
		~Texture2DAssetLoader() = default;


		// Inherited via IAssetResolver
		virtual RudyObject* Load(const ByteBlock& assetContentBytes) override;

	};


}