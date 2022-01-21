#include "AssetUtilities.h"
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <stdio.h>
namespace Rudy
{
	AssetType AssetUtilities::GetAssetTypeViaExtension(const String& filePath)
	{
		/*
		* Get extenion
		*/
		String extension;
		PlatformFile::GetFileExtension(filePath,extension);

		/*
		* Catch
		*/
		printf("Extension check: %s || %s\n", *extension,*filePath);
		if (extension == ".jpg" || extension == ".png" || extension == ".jpeg")
		{
			return AssetType::Texture2D;
		}
		return AssetType::Undefined;
	}
}