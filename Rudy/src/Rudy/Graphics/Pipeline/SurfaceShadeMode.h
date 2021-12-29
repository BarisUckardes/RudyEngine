#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Graphics api agnostic supported surface shader models
	/// </summary>
	enum class RUDY_API SurfaceShadeModel
	{
		Fill = 0,
		Point = 1,
		Line = 2
	};
}