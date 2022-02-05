#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Reflection/Object/ReflectableObject.h>
namespace Rudy
{
	/// <summary>
	/// Represents an asset
	/// </summary>
	class __declspec(dllexport) AssetObject : public ReflectableObject
	{
		friend class AssetPackage;
	public:
		GENERATE_REFLECTABLE_OBJECT(AssetObject);
		/// <summary>
		/// Frees this asset
		/// </summary>
		void FreeAsset();

		/// <summary>
		/// Returns whether this asset freed or not
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsAssetFreed() const;
	protected:
		virtual void FreeAssetCore() = 0;
	private:
		bool m_bFree;
	};
	GENERATE_REFLECTABLE_TYPE(AssetObject);

}
