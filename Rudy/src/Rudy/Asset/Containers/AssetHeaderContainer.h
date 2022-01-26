#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/Guid.h>
#include <Rudy/Asset/AssetType.h>
namespace Rudy
{
	/// <summary>
	/// Data volume for asset headers
	/// </summary>
	struct AssetHeaderContainer
	{

		/// <summary>
		/// Type of the asset
		/// </summary>
		AssetType Type;

		/// <summary>
		/// Unique id of the asset
		/// </summary>
		Guid ID;

		/// <summary>
		/// Name of the asset
		/// </summary>
		char Name[20];

		/// <summary>
		/// Asset content start byte
		/// </summary>
		unsigned long Offset;

		/// <summary>
		/// Asset content size in bytes
		/// </summary>
		unsigned long Size;
	};
}