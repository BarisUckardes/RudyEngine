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
		/// Returns the package with the matching id
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		FORCEINLINE AssetPackage* GetPackage(const Guid& id) const;
	private:
		Array<AssetPackage*> m_Packages;
	};


}