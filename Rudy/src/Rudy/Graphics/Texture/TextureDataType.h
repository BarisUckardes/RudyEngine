#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported texture data types
	/// </summary>
	enum class RUDY_API TextureDataType
	{
        None = 0,
        Byte = 1,
        UnsignedByte = 2,
        Short = 3,
        UnsignedShort = 4,
        Int = 5,
        UnsignedInt = 6,
        Float = 7,
        HalfFloat = 8,
        UnsignedByte332 = 9,
        UnsignedByte332Ext = 10,
        UnsignedShort4444 = 11,
        UnsignedShort4444Ext = 12,
        UnsignedShort5551 = 13,
        UnsignedShort5551Ext = 14,
        UnsignedInt8888 = 15,
        UnsignedInt8888Ext = 16,
        UnsignedInt1010102 = 17,
        UnsignedInt1010102Ext = 18,
        UnsignedByte233Reversed = 19,
        UnsignedShort565 = 20,
        UnsignedShort565Reversed = 21,
        UnsignedShort4444Reversed = 22,
        UnsignedShort1555Reversed = 23,
        UnsignedInt8888Reversed = 24,
        UnsignedInt2101010Reversed = 25,
        UnsignedInt248 = 26,
        UnsignedInt10F11F11FRev = 27,
        UnsignedInt5999Rev = 28,
        Float32UnsignedInt248Rev = 29
	};
}