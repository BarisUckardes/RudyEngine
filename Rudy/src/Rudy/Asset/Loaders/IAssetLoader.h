#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	class ApplicationSession;
	class ByteBlock;
	class AssetObject;
	/// <summary>
	/// Asset loader interface for the custom asset loaders to implement
	/// </summary>
	class RUDY_API IAssetLoader
	{
	public:
		IAssetLoader(ApplicationSession* session);
		~IAssetLoader();


		/// <summary>
		/// Loads an asset object
		/// </summary>
		/// <param name="assetContentBytes"></param>
		/// <returns></returns>
		virtual AssetObject* Load(const ByteBlock& assetContentBytes) = 0;

	protected:

		/// <summary>
		/// Returns the application session for derived classes
		/// </summary>
		/// <returns></returns>
		FORCEINLINE ApplicationSession* GetSession() const;
	private:
		ApplicationSession* m_Session;
	};


}