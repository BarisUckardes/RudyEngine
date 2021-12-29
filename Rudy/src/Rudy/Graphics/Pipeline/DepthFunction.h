#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Graphics api agnostic supported depth function
	/// </summary>
	enum class RUDY_API DepthFunction
	{
		Never = 0,
		Less = 1,
		Equal = 2,
		Lequal = 3,
		Greater = 4,
		Notequal = 5,
		Gequal = 6,
		Always = 7
	};
}