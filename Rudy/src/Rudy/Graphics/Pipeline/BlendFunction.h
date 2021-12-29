#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Graphics api agnostic supported blend functions
	/// </summary>
	enum class RUDY_API BlendFunction
	{
		Zero = 1,
		One = 2,
		SourceColor = 3,
		OneMinusSourceColor = 4,
		DestColor = 5,
		OneMinusDestColor = 6,
		SourceAlpha = 7,
		OneMinusSourceAlpha = 8,
		DestAlpha = 9,
		OneMinusDestAlpha = 10,
		ConstantColor = 11,
		OneMinusConstantColor = 12,
		ConstantAlpha = 13,
		OneMinusConstantAlpha = 14
	};
}