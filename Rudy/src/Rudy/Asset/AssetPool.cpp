#include "AssetPool.h"
#include <Rudy/Asset/AssetPackage.h>
namespace Rudy
{
	AssetPool::AssetPool(const Array<String>& packagePaths)
	{
		/*
		* Load asset packages from the paths
		*/
		for (int i = 0; i < packagePaths.GetCursor(); i++)
		{
			/*
			* Get path string
			*/
			const String& path = packagePaths[i];

			/*
			* Create package with the path
			*/
			AssetPackage* package = new AssetPackage(path);

			/*
			* Register package
			*/
			m_Packages.Add(package);
		}
	}
	AssetPool::~AssetPool()
	{
		/*
		* Iterate and delete packages
		*/
		for (int i = 0; i < m_Packages.GetCursor(); i++)
		{
			/*
			* Get package
			*/
			AssetPackage* package = m_Packages[i];

			/*
			* Delete package
			*/
			delete package;
		}
		m_Packages.Clear();
	}
	AssetPackage* AssetPool::GetPackage(const Guid& id) const
	{
		/*
		* Iterate and validate
		*/
		for (int i = 0; i < m_Packages.GetCursor(); i++)
		{
			/*
			* Get package
			*/
			AssetPackage* package = m_Packages[i];

			/*
			* Validate
			*/
			if (package->GetPackageID() == id)
			{
				return package;
			}
		}

		return nullptr;
	}
}