#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Graphics api agnostic supported blend equations
	/// </summary>
	enum class RUDY_API BlendEquation
	{
		FuncAdd = 0,
		Min = 1,
		Max = 2,
		FuncSubtract = 3,
		FuncReverseSubtract = 4
	};
}