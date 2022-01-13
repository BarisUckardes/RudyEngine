#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// The transfer operations for byte block
	/// </summary>
	enum class RUDY_API ByteBlockTransferType
	{
		Copy = 0,
		Move = 1
	};
}