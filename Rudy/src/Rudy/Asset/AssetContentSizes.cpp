#include "AssetContentSizes.h"
#include <Rudy/Asset/AssetWriteConstants.h>
namespace Rudy
{
	unsigned long AssetContentSizes::GetAssetTypeContentSize(AssetType type)
	{
		switch (type)
		{
		case Rudy::AssetType::Undefined:
			break;
		case Rudy::AssetType::Prefab:
			break;
		case Rudy::AssetType::World:
			break;
		case Rudy::AssetType::Texture1D:
			break;
		case Rudy::AssetType::Texture2D:
			break;
		case Rudy::AssetType::Texture3D:
			break;
		case Rudy::AssetType::CubeTexture:
			break;
		case Rudy::AssetType::Material:
			break;
		case Rudy::AssetType::Shader:
			return 4 + ASSET_WRITE_MAX_NAME;
			break;
		case Rudy::AssetType::ShaderProgram:
			return 4 + ASSET_WRITE_MAX_NAME + ASSET_WRITE_MAX_NAME;
			break;
		case Rudy::AssetType::Mesh:
			break;
		case Rudy::AssetType::Framebuffer2D:
			break;
		default:
			break;
		}
	}
}