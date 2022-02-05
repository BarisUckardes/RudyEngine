#include "AssetObject.h"

namespace Rudy
{
	void AssetObject::FreeAsset()
	{
		/*
		* Call implementation
		*/
		FreeAssetCore();

		/*
		* Mark as destroyed
		*/
		m_bFree = true;
	}

	bool AssetObject::IsAssetFreed() const
	{

		return m_bFree;
	}

}