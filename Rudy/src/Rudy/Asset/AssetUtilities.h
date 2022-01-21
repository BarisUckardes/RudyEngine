#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Asset/AssetType.h>
namespace Rudy
{
	class String;
	/// <summary>
	/// Utility methods for asset layer
	/// </summary>
	class RUDY_API AssetUtilities
	{
	public:
		AssetUtilities() = delete;
		~AssetUtilities() = delete;

		static AssetType GetAssetTypeViaExtension(const String& filePath);
	};


}