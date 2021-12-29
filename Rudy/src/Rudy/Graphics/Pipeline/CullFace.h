#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Graphics api agnostic supported cull faces
	/// </summary>
	enum class RUDY_API CullFace
	{
		Front = 0,
		Back = 1,
		FrontAndBack = 2
	};
}