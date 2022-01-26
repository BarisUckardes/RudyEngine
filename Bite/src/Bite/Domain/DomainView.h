#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>

namespace Rudy
{
	class AssetPackage;
}
namespace Bite
{
	class DomainFolderView;
	class EditorSession;
	/// <summary>
	/// Represents a editor's view of the domain
	/// </summary>
	class BITE_API DomainView
	{
	public:
		DomainView(const Rudy::String& domainPath,EditorSession* package);
		DomainView() = delete;
		~DomainView();

		/// <summary>
		/// Returns the root folder view of this domain
		/// </summary>
		/// <returns></returns>
		FORCEINLINE DomainFolderView* GetRootFolder() const;
	private:
		/// <summary>
		/// Loads intial domain view
		/// </summary>
		void Initialize();

		DomainFolderView* m_RootFolder;
		EditorSession* m_OwnerSession;
		Rudy::String m_DomainPath;
	};


}