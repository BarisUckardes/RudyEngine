#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported asset types
	/// </summary>
	enum class RUDY_API AssetType
	{
		Undefined = 0,
		Prefab = 1,
		World = 2,
		Texture1D = 3,
		Texture2D = 4,
		Texture3D = 5,
		CubeTexture = 6,
		Material = 7,
		Shader = 8,
		ShaderProgram = 9,
		Mesh = 10,
		Framebuffer2D = 11
	};
}