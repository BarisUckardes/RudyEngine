#pragma once
#include <Rudy/Memory/Array.h>
#include <Rudy/Memory/String.h>
namespace Rudy
{
	class AssetPackage;
	class Asset;
	class Guid;

	/// <summary>
	/// Represents total asset volume
	/// </summary>
	class RUDY_API AssetPool
	{
	public:
		AssetPool(const Array<String>& packagePaths);
		~AssetPool();

		/// <summary>
		/// Creates a virtual asset package
		/// </summary>
		/// <returns></returns>
		FORCEINLINE AssetPackage* CreateVirtualPackage();

		/// <summary>
		/// Tries to delete the virtual package
		/// </summary>
		/// <param name="packageID"></param>
		/// <returns></returns>
		FORCEINLINE bool DeleteVirtualPackage(const Guid& packageID);

		/// <summary>
		/// Returns the package with the matching id
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		FORCEINLINE AssetPackage* GetPackage(const Guid& id) const;

		/// <summary>
		/// Returns the total allocated pool size
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned long GetAllocatedPackageSize() const;

		/// <summary>
		/// Returns the total amount of asset bytes this pool has
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned long GetTotalPackageSize() const;

		/// <summary>
		/// Returns all the packages this pool has
		/// </summary>
		/// <returns></returns>
		Array<AssetPackage*> GetPackages() const;
	private:
		Array<AssetPackage*> m_Packages;
	};
}