#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Guid.h>
#include <Rudy/Asset/AssetType.h>
namespace Rudy
{
	class AssetPackage;
}
namespace Bite
{
	class DomainAssetView;
	class DomainFolderView;
	class EditorSession;

	/// <summary>
	/// Represetns a folder in the domain view
	/// </summary>
	class BITE_API DomainFolderView
	{
		friend class DomainView;
	public:
		/// <summary>
		/// Returns the sub folders
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::Array<DomainFolderView*> GetSubFolders() const;

		/// <summary>
		/// Returns the files
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::Array<DomainAssetView*> GetAssets() const;

		/// <summary>
		/// Returns the root folder of this folder
		/// </summary>
		/// <returns></returns>
		FORCEINLINE DomainFolderView* GetParentFolder() const;

		/// <summary>
		/// Returns the unique id per session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::Guid GetID() const;

		/// <summary>
		/// Returns the name of this folder
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::String GetName() const;

		/// <summary>
		/// Returns the absolute path of this folder
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::String GetAbsolutePath() const;

		/// <summary>
		/// Creates anew folder
		/// </summary>
		/// <param name="folderName"></param>
		void CreateSubFolder(const Rudy::String& folderName);

		/// <summary>
		/// Registers an external asset
		/// </summary>
		/// <param name="path"></param>
		void CreateAsset(const Rudy::String& name,Rudy::AssetType assetType,void* parameter);
	private:
		DomainFolderView(DomainFolderView* parentFolder,
			const Rudy::String& selfPath,EditorSession* editorSession);
		~DomainFolderView() = default;

		Rudy::Array<DomainFolderView*> m_SubFolders;
		Rudy::Array<DomainAssetView*> m_Assets;;
		DomainFolderView* m_ParentFolder;
		EditorSession* m_OwnerSession;
		Rudy::Guid m_ID;
		Rudy::String m_Name;
		Rudy::String m_AbsolutePath;
	};


}