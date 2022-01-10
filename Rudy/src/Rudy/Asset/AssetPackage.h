#pragma once
#include <Rudy/Asset/AssetDefinition.h>
namespace Rudy
{
	class RudyObject;
	class Asset;
	/// <summary>
	/// Represents a collection of assets
	/// </summary>
	class RUDY_API AssetPackage
	{
		friend class AssetPool;
	public:
		AssetPackage(const String& packagePath);
		~AssetPackage();

		/// <summary>
		/// Registers anew virtual asset
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		Asset* RegisterVirtualAsset(const String& path);

		/// <summary>
		/// Removes a virtual asset
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		bool RemoveVirtualAsset(const Guid& id);

		/// <summary>
		/// Tries to load an asset with the specificed id
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		const Asset* LoadAsset(const Guid& id);

		/// <summary>
		/// Tries to unload and asset
		/// </summary>
		/// <param name="id"></param>
		void UnloadAsset(const Guid& id);

		/// <summary>
		/// Unloads the whole package
		/// </summary>
		void UnloadPackage();

		/// <summary>
		/// Returns the defintions of an asset
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		FORCEINLINE AssetDefinition GetDefiniton(const Guid& id);

		/// <summary>
		/// Returns the id of this package
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Guid GetPackageID() const;

		/// <summary>
		/// Returns the total size of this asset package
		/// </summary>
		FORCEINLINE unsigned long GetTotalAssetSize() const;

		/// <summary>
		/// Returns the allocated memory for this package
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned long GetAllocatedAssetSize() const;

		/// <summary>
		/// Returns whether this package is virtually created.(runtime)
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsVirtual() const;

		/// <summary>
		/// Returns all the definitions this asset package has
		/// </summary>
		/// <returns></returns>
		Array<AssetDefinition> GetDefinitions() const;
	private:
		AssetPackage();
		Array<Asset*> m_Assets;
		Array<AssetDefinition> m_Definitions;
		Guid m_PackageID;
		String m_PackagePath;
		bool m_bVirtual;
	};


}