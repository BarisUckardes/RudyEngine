#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported graphics api type
	/// </summary>
	enum class RUDY_API GraphicsAPIType
	{
		Undefined = 0,
		OpenGL = 1,
		DÝrectx9 = 2,
		Directx11 = 3,
		Directx12 = 4,
		Directx13 = 5,
		Vulkan = 6
	};
}