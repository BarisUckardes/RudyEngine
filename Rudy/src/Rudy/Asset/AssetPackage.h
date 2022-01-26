#pragma once
#include <Rudy/Asset/AssetDefinition.h>
#include <Rudy/Asset/Containers/AssetHeaderContainer.h>
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
		/// <summary>
		/// Creates the package via path, this means its' a not raw asset package
		/// </summary>
		/// <param name="packagePath"></param>
		AssetPackage(const String& packagePath);

		/// <summary>
		/// Creates the package in memeory(virtual package)
		/// </summary>
		AssetPackage();

		~AssetPackage();

		/// <summary>
		/// Registers anew virtual asset
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		Asset* RegisterVirtualAsset(const String& path,bool bTargetsRawFile);
		
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
		FORCEINLINE Asset* GetAsset(const Guid& id);

		/// <summary>
		/// Unloads the whole package
		/// </summary>
		void UnloadPackage();

		/// <summary>
		/// Returns the defintions of an asset
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		FORCEINLINE AssetHeaderContainer GetHeader(const Guid& id);

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
		Array<AssetHeaderContainer> GetHeaders() const;
	private:
		Array<Asset*> m_Assets;
		Array<AssetHeaderContainer> m_Headers;
		Guid m_PackageID;
		String m_PackagePath;
		bool m_bVirtual;
	};


}