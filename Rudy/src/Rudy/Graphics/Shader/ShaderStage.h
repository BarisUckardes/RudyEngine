#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported shader types
	/// </summary>
	enum class RUDY_API ShaderStage
	{
		None = 0,
		Vertex = 1,
		Fragment = 2,
		Geometry = 3
	};
}