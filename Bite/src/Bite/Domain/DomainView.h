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

	/// <summary>
	/// Represents a editor's view of the domain
	/// </summary>
	class BITE_API DomainView
	{
	public:
		DomainView(const Rudy::String& domainPath,Rudy::AssetPackage* package);
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
		void Initialize(Rudy::AssetPackage* package);

		DomainFolderView* m_RootFolder;
		Rudy::String m_DomainPath;
	};


}