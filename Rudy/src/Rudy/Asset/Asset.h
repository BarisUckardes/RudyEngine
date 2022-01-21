#pragma once
#include <Rudy/Object/RudyObject.h>
#include <Rudy/Asset/AssetDefinition.h>
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
		Asset(const AssetDefinition& definition,AssetPackage* ownerPackage,bool btargetsRawFile);

		/// <summary>
		/// Loads the asset if hasnt already
		/// </summary>
		void Load(ApplicationSession* session);

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

		/// <summary>
		/// returns the loaded asset
		/// </summary>
		/// <returns></returns>
		FORCEINLINE RudyObject* GetLoadedObject() const;

		/// <summary>
		/// Returns the owner package of this asset
		/// </summary>
		/// <returns></returns>
		FORCEINLINE AssetPackage* GetOwnerPackage() const;

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
	private:
		~Asset();
		RudyObject* m_LoadedObject;
		AssetPackage* m_OwnerPackage;
		AssetDefinition m_Definition;
		unsigned long m_SizeInBytes;
		bool m_bTargetsRawFile;
	};


}