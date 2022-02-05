#pragma once
#include <Rudy/Asset/AssetType.h>

namespace Rudy
{
	class RUDY_API AssetContentSizes
	{
	public:
		AssetContentSizes() = delete;
		~AssetContentSizes() = delete;

		static unsigned long GetAssetTypeContentSize(AssetType type);
	};


}