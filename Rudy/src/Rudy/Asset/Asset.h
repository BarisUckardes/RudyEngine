#pragma once
#include <Rudy/Object/AssetObject.h>
#include <Rudy/Asset/AssetDefinition.h>
#include <Rudy/Asset/Containers/AssetHeaderContainer.h>
#include <Rudy/Memory/ByteBlock.h>
namespace Rudy
{
	class AssetPackage;
	class ApplicationSession;
	/// <summary>
	/// Represents a single loaded asset
	/// </summary>
	class RUDY_API Asset
	{
		friend class AssetPackage;
	public:
		Asset(const AssetHeaderContainer& header,const String& assetAbsolutePath,AssetPackage* ownerPackage,bool btargetsRawFile);

		/// <summary>
		/// returns the loaded asset
		/// </summary>
		/// <returns></returns>
		FORCEINLINE AssetObject* GetLoadedObject() const;

		/// <summary>
		/// Returns the owner package of this asset
		/// </summary>
		/// <returns></returns>
		FORCEINLINE AssetPackage* GetOwnerPackage() const;

		/// <summary>
		/// Returns the asset definition
		/// </summary>
		/// <returns></returns>
		FORCEINLINE AssetHeaderContainer GetAssetHeader() const;

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

		/// <summary>
		/// Returns whether this asset is a raw file
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsRawFile() const;

		/// <summary>
		/// Returns whether this asset cached its contents.So there is no need to read it from file
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool HasCache() const;

		/// <summary>
		/// Loads the asset if hasnt already
		/// </summary>
		void Load(ApplicationSession* session,bool bCacheLoadedData);

		/// <summary>
		/// Loads file content into memory
		/// </summary>
		/// <param name="bCacheAsync"></param>
		void Cache(bool bCacheAsync);

		/// <summary>
		/// Deletes the cached memory
		/// </summary>
		void DeleteCache();

		/// <summary>
		/// Unloads the asset if its loaded
		/// </summary>
		void Unload();
	private:
		~Asset();
		AssetObject* m_LoadedObject;
		AssetPackage* m_OwnerPackage;
		Rudy::ByteBlock m_CachedData;
		AssetHeaderContainer m_Header;
		String m_AbsolutePath;
		unsigned long m_SizeInBytes;
		bool m_bTargetsRawFile;
		bool m_bHasCache;
	};


}