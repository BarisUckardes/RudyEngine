#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported texture wrap modes
	/// </summary>
	enum class RUDY_API TextureWrapMode
	{
		Clamp = 0,
		ClampToEdge= 1,
		ClampToBorder = 2,
		Repeat = 3,
		Mirror = 4
	};
}