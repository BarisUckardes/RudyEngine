#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported texture minification filter
	/// </summary>
	enum class RUDY_API TextureMinFilter
	{
		Nearest = 0,
		Linear = 1,
		NearestMipmapNearest = 2,
		LinearMimpmapNearest = 3,
		NearestMippmapLinear = 4,
		LinearMipmapLinear = 5,
	};
}