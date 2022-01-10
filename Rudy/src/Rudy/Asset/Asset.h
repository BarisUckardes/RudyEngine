#pragma once
#include <Rudy/Object/RudyObject.h>
#include <Rudy/Asset/AssetDefinition.h>
namespace Rudy
{
	/// <summary>
	/// Represents a single loaded asset
	/// </summary>
	class RUDY_API Asset
	{
		friend class AssetPackage;
	public:
		Asset(const AssetDefinition& definition);

		/// <summary>
		/// Loads the asset if hasnt already
		/// </summary>
		void Load();

		/// <summary>
		/// Unloads the asset if its loaded
		/// </summary>
		void Unload();

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

		/// <summary>
		/// Returns the total size of this asset in bytes
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned long GetSizeInBytes() const;

		/// <summary>
		/// Returns whether this asset
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsLoaded() const;

	private:
		~Asset();
		RudyObject* m_LoadedObject;
		AssetDefinition m_Definition;
		unsigned long m_SizeInBytes;
	};


}