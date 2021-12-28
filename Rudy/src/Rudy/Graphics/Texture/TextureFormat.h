#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported texture formats
	/// </summary>
	enum class RUDY_API TextureFormat
	{
        None = 0,
        UnsignedShort = 1,
        UnsignedInt = 2,
        ColorIndex = 3,
        StencilIndex = 4,
        DepthComponent = 5,
        Red = 6,
        RedExt = 7,
        Green = 8,
        Blue = 9,
        Alpha = 10,
        Rgb = 11,
        Rgba = 12,
        Luminance = 13,
        LuminanceAlpha = 14,
        AbgrExt = 15,
        CmykExt = 16,
        CmykaExt = 17,
        Bgr = 18,
        Bgra = 19,
        Ycrcb422Sgix = 20,
        Ycrcb444Sgix = 21,
        Rg = 22,
        RgInteger = 23,
        R5G6B5IccSgix = 24,
        R5G6B5A8IccSgix = 25,
        Alpha16IccSgix = 26,
        Luminance16IccSgix = 27,
        Luminance16Alpha8IccSgix = 28,
        DepthStencil = 29,
        RedInteger = 30,
        GreenInteger = 31,
        BlueInteger = 32,
        AlphaInteger = 33,
        RgbInteger = 34,
        RgbaInteger = 35,
        BgrInteger = 36,
        BgraInteger = 37
	};
}