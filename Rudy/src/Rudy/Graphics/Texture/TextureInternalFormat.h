#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported internal texture formats
	/// </summary>
	enum class RUDY_API TextureInternalFormat
	{
        None = 0,
        One = 1,
        Two = 2,
        Three = 3,
        Four = 4,
        DepthComponent = 5,
        Alpha = 6,
        Rgb = 7,
        Rgba = 8,
        Luminance = 9,
        LuminanceAlpha = 10,
        R3G3B2 = 11,
        Rgb2Ext = 12,
        Rgb4 = 13,
        Rgb5 = 14,
        Rgb8 = 15,
        Rgb10 = 16,
        Rgb12 = 17,
        Rgb16 = 18,
        Rgba2 = 19,
        Rgba4 = 20,
        Rgb5A1 = 21,
        Rgba8 = 22,
        Rgb10A2 = 23,
        Rgba12 = 24,
        Rgba16 = 25,
        DualAlpha4Sgis = 26,
        DualAlpha8Sgis = 27,
        DualAlpha12Sgis = 28,
        DualAlpha16Sgis = 29,
        DualLuminance4Sgis = 30,
        DualLuminance8Sgis = 31,
        DualLuminance12Sgis = 32,
        DualLuminance16Sgis = 33,
        DualIntensity4Sgis = 34,
        DualIntensity8Sgis = 35,
        DualIntensity12Sgis = 36,
        DualIntensity16Sgis = 37,
        DualLuminanceAlpha4Sgis = 38,
        DualLuminanceAlpha8Sgis = 39,
        QuadAlpha4Sgis = 40,
        QuadAlpha8Sgis = 41,
        QuadLuminance4Sgis = 42,
        QuadLuminance8Sgis = 43,
        QuadIntensity4Sgis = 44,
        QuadIntensity8Sgis = 45,
        DepthComponent16 = 46,
        DepthComponent16Sgix = 47,
        DepthComponent24 = 48,
        DepthComponent24Sgix = 49,
        DepthComponent32 = 50,
        DepthComponent32Sgix = 51,
        CompressedRed = 52,
        CompressedRg = 53,
        R8 = 54,
        R16 = 55,
        Rg8 = 56,
        Rg16 = 57,
        R16f = 58,
        R32f = 59,
        Rg16f = 60,
        Rg32f = 61,
        R8i = 62,
        R8ui = 63,
        R16i = 64,
        R16ui = 65,
        R32i = 66,
        R32ui = 67,
        Rg8i = 68,
        Rg8ui = 69,
        Rg16i = 70,
        Rg16ui = 71,
        Rg32i = 72,
        Rg32ui = 73,
        CompressedRgbS3tcDxt1Ext = 74,
        CompressedRgbaS3tcDxt1Ext = 75,
        CompressedRgbaS3tcDxt3Ext = 76,
        CompressedRgbaS3tcDxt5Ext = 77,
        RgbIccSgix = 78,
        RgbaIccSgix = 79,
        AlphaIccSgix = 80,
        LuminanceIccSgix = 81,
        IntensityIccSgix = 82,
        LuminanceAlphaIccSgix = 83,
        R5G6B5IccSgix = 84,
        R5G6B5A8IccSgix = 85,
        Alpha16IccSgix = 86,
        Luminance16IccSgix = 87,
        Intensity16IccSgix = 88,
        Luminance16Alpha8IccSgix = 89,
        CompressedAlpha = 90,
        CompressedLuminance = 91,
        CompressedLuminanceAlpha = 92,
        CompressedIntensity = 93,
        CompressedRgb = 94,
        CompressedRgba = 95,
        DepthStencil = 96,
        Rgba32f = 97,
        Rgb32f = 98,
        Rgba16f = 99,
        Rgb16f = 100,
        Depth24Stencil8 = 101,
        R11fG11fB10f = 102,
        Rgb9E5 = 103,
        Srgb = 104,
        Srgb8 = 105,
        SrgbAlpha = 106,
        Srgb8Alpha8 = 107,
        SluminanceAlpha = 108,
        Sluminance8Alpha8 = 109,
        Sluminance = 110,
        Sluminance8 = 111,
        CompressedSrgb = 112,
        CompressedSrgbAlpha = 113,
        CompressedSluminance = 114,
        CompressedSluminanceAlpha = 115,
        CompressedSrgbS3tcDxt1Ext = 116,
        CompressedSrgbAlphaS3tcDxt1Ext = 117,
        CompressedSrgbAlphaS3tcDxt3Ext = 118,
        CompressedSrgbAlphaS3tcDxt5Ext = 119,
        DepthComponent32f = 120,
        Depth32fStencil8 = 121,
        Rgba32ui = 122,
        Rgb32ui = 123,
        Rgba16ui = 124,
        Rgb16ui = 125,
        Rgba8ui = 126,
        Rgb8ui = 127,
        Rgba32i = 128,
        Rgb32i = 129,
        Rgba16i = 130,
        Rgb16i = 131,
        Rgba8i = 132,
        Rgb8i = 133,
        Float32UnsignedInt248Rev = 134,
        CompressedRedRgtc1 = 135,
        CompressedSignedRedRgtc1 = 136,
        CompressedRgRgtc2 = 137,
        CompressedSignedRgRgtc2 = 138,
        CompressedRgbaBptcUnorm = 139,
        CompressedSrgbAlphaBptcUnorm = 140,
        CompressedRgbBptcSignedFloat = 141,
        CompressedRgbBptcUnsignedFloat = 142,
        R8Snorm = 143,
        Rg8Snorm = 144,
        Rgb8Snorm = 145,
        Rgba8Snorm = 146,
        R16Snorm = 147,
        Rg16Snorm = 148,
        Rgb16Snorm = 149,
        Rgba16Snorm = 150,
        Rgb10A2ui = 151
	};
}