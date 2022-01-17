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
	AssetPackage* AssetPool::CreateVirtualPackage()
	{
		/*
		* Create new package
		*/
		AssetPackage* package = new AssetPackage();

		/*
		* Register package
		*/
		m_Packages.Add(package);

		return package;
	}
	bool AssetPool::DeleteVirtualPackage(const Guid& packageID)
	{
		/*
		* Iterate and validate packages
		*/
		for (int i = 0; i < m_Packages.GetCursor(); i++)
		{
			/*
			* Get packages
			*/
			AssetPackage* package = m_Packages[i];

			/*
			* Validate virtual
			*/
			if (!package->IsVirtual())
				continue;

			/*
			* Unload package
			*/
			package->UnloadPackage();
			delete package;
			m_Packages.RemoveIndex(i);
			return true;
		}
		return false;
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
	unsigned long AssetPool::GetAllocatedPackageSize() const
	{
		unsigned long allocatedSize = 0;

		/*
		* Iterate and gather allocated size
		*/
		for (int i = 0; i < m_Packages.GetCursor(); i++)
		{
			/*
			* Get package
			*/
			AssetPackage* package = m_Packages[i];

			/*
			* Get and increment
			*/
			allocatedSize += package->GetAllocatedAssetSize();
		}

		return allocatedSize;
	}
	unsigned long AssetPool::GetTotalPackageSize() const
	{
		unsigned long totalSize = 0;

		/*
		* Iterate and gather allocated size
		*/
		for (int i = 0; i < m_Packages.GetCursor(); i++)
		{
			/*
			* Get package
			*/
			AssetPackage* package = m_Packages[i];

			/*
			* Get and increment
			*/
			totalSize += package->GetTotalAssetSize();
		}

		return totalSize;
	}
	Array<AssetPackage*> AssetPool::GetPackages() const
	{
		return m_Packages;
	}
	Asset* AssetPool::GetAsset(const Guid& id)
	{
		/*
		* Iterate each package
		*/
		for (unsigned int packageIndex = 0; packageIndex < m_Packages.GetCursor(); packageIndex++)
		{
			/*
			* Get package
			*/
			AssetPackage* package = m_Packages[packageIndex];

			/*
			* Try get asset
			*/
			Asset* asset = package->GetAsset(id);

			/*
			* Validate
			*/
			if (asset == nullptr)
				continue;

			return asset;
		}
		return nullptr;
	}
}