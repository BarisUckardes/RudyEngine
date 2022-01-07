#pragma once
#include <Rudy/Object/RudyObject.h>

namespace Rudy
{
	/// <summary>
	/// Represents a single loaded asset
	/// </summary>
	class RUDY_API Asset
	{
		friend class AssetPackage;
	public:
		Asset(RudyObject* assetObject,const Guid& id);

		/// <summary>
		/// returns the loaded asset
		/// </summary>
		/// <returns></returns>
		FORCEINLINE RudyObject* GetLoadedObject() const;

		/// <summary>
		/// Returns the asset id
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Guid GetID() const;
	private:
		~Asset();
		RudyObject* m_LoadedObject;
		Guid m_ID;
	};


}