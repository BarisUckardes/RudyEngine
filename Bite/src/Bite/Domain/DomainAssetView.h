#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Asset/AssetDefinition.h>

namespace Rudy
{
	class Asset;
	class RudyObject;
}
namespace Bite
{
	class EditorSession;
	/// <summary>
	/// Reprensets an asset in a domain
	/// </summary>
	class BITE_API DomainAssetView
	{
	public:
		DomainAssetView(const Rudy::String& absoluteAssetPath,EditorSession* session);
		DomainAssetView() = delete;
		~DomainAssetView();

		/// <summary>
		/// Tries to load the target asset of this asset view
		/// </summary>
		/// <param name="bLoadAsync"></param>
		void TryLoadAsset(bool bLoadAsync = false);

		/// <summary>
		/// Deletes this asset from the view and the asset pool
		/// </summary>
		void DeleteAsset();

		/// <summary>
		/// Renames this asset
		/// </summary>
		/// <param name="name"></param>
		void RenameAsset(const Rudy::String& name);

		/// <summary>
		/// Returns the taret asset object of this asset view
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::RudyObject* GetAssetObject() const;

		/// <summary>
		/// Returns the asset name
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::String GetAssetName() const;
	private:
		Rudy::Asset* m_TargetAsset;
		EditorSession* m_OwnerSession;
		Rudy::AssetDefinition m_Definition;
		Rudy::String m_AbsolutePath;
		Rudy::String m_AssetName;
	};


}