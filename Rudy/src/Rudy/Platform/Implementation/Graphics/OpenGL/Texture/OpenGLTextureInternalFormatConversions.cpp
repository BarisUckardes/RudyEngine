#include "OpenGLTextureInternalFormatConversions.h"
#include <GLAD/glad.h>
#include <stdio.h>
namespace Rudy
{
	unsigned int OpenGLTextureInternalFormatConversions::GetOpenGLTextureInternalFormat(TextureInternalFormat internalFormat)
	{
		switch (internalFormat)
		{
			case Rudy::TextureInternalFormat::None:
				return GL_NONE;
				break;
			case Rudy::TextureInternalFormat::One:
				return GL_ONE;
				break;
			case Rudy::TextureInternalFormat::Two:
				return 0;
				break;
			case Rudy::TextureInternalFormat::Three:
				return 0;
				break;
			case Rudy::TextureInternalFormat::Four:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DepthComponent:
				return GL_DEPTH_COMPONENT;
				break;
			case Rudy::TextureInternalFormat::Alpha:
				return GL_ALPHA;
				break;
			case Rudy::TextureInternalFormat::Rgb:
				return GL_RGB;
				break;
			case Rudy::TextureInternalFormat::Rgba:
				return GL_RGBA;
				break;
			case Rudy::TextureInternalFormat::Luminance:
				return GL_LUMINANCE;
				break;
			case Rudy::TextureInternalFormat::LuminanceAlpha:
				return GL_LUMINANCE_ALPHA;
				break;
			case Rudy::TextureInternalFormat::R3G3B2:
				return GL_R3_G3_B2;
				break;
			case Rudy::TextureInternalFormat::Rgb2Ext:
				return 0;
				break;
			case Rudy::TextureInternalFormat::Rgb4:
				return GL_RGB4;
				break;
			case Rudy::TextureInternalFormat::Rgb5:
				return GL_RGB5;
				break;
			case Rudy::TextureInternalFormat::Rgb8:
				return GL_RGB8;
				break;
			case Rudy::TextureInternalFormat::Rgb10:
				return GL_RGB10;
				break;
			case Rudy::TextureInternalFormat::Rgb12:
				return GL_RGB12;
				break;
			case Rudy::TextureInternalFormat::Rgb16:
				return GL_RGB16;
				break;
			case Rudy::TextureInternalFormat::Rgba2:
				return GL_RGBA2;
				break;
			case Rudy::TextureInternalFormat::Rgba4:
				return GL_RGBA4;
				break;
			case Rudy::TextureInternalFormat::Rgb5A1:
				return GL_RGB5_A1;
				break;
			case Rudy::TextureInternalFormat::Rgba8:
				return GL_RGBA8;
				break;
			case Rudy::TextureInternalFormat::Rgb10A2:
				return GL_RGB10_A2;
				break;
			case Rudy::TextureInternalFormat::Rgba12:
				return GL_RGBA12;
				break;
			case Rudy::TextureInternalFormat::Rgba16:
				return GL_RGBA16;
				break;
			case Rudy::TextureInternalFormat::DualAlpha4Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualAlpha8Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualAlpha12Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualAlpha16Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualLuminance4Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualLuminance8Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualLuminance12Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualLuminance16Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualIntensity4Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualIntensity8Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualIntensity12Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualIntensity16Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualLuminanceAlpha4Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DualLuminanceAlpha8Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::QuadAlpha4Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::QuadAlpha8Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::QuadLuminance4Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::QuadLuminance8Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::QuadIntensity4Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::QuadIntensity8Sgis:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DepthComponent16:
				return GL_DEPTH_COMPONENT16;
				break;
			case Rudy::TextureInternalFormat::DepthComponent16Sgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DepthComponent24:
				return GL_DEPTH_COMPONENT24;
				break;
			case Rudy::TextureInternalFormat::DepthComponent24Sgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DepthComponent32:
				return GL_DEPTH_COMPONENT32;
				break;
			case Rudy::TextureInternalFormat::DepthComponent32Sgix:
				break;
			case Rudy::TextureInternalFormat::CompressedRed:
				return GL_COMPRESSED_RED;
				break;
			case Rudy::TextureInternalFormat::CompressedRg:
				return GL_COMPRESSED_RG;
				break;
			case Rudy::TextureInternalFormat::R8:
				return GL_R8;
				break;
			case Rudy::TextureInternalFormat::R16:
				return GL_R16;
				break;
			case Rudy::TextureInternalFormat::Rg8:
				return GL_RG8;
				break;
			case Rudy::TextureInternalFormat::Rg16:
				return GL_RG16;
				break;
			case Rudy::TextureInternalFormat::R16f:
				return GL_R16F;
				break;
			case Rudy::TextureInternalFormat::R32f:
				return GL_R32F;
				break;
			case Rudy::TextureInternalFormat::Rg16f:
				return GL_RG16F;
				break;
			case Rudy::TextureInternalFormat::Rg32f:
				return GL_RG32F;
				break;
			case Rudy::TextureInternalFormat::R8i:
				return GL_R8I;
				break;
			case Rudy::TextureInternalFormat::R8ui:
				return GL_R8UI;
				break;
			case Rudy::TextureInternalFormat::R16i:
				return GL_R16I;
				break;
			case Rudy::TextureInternalFormat::R16ui:
				return GL_R16UI;
				break;
			case Rudy::TextureInternalFormat::R32i:
				return GL_R32I;
				break;
			case Rudy::TextureInternalFormat::R32ui:
				return GL_R32UI;
				break;
			case Rudy::TextureInternalFormat::Rg8i:
				return GL_RG8I;
				break;
			case Rudy::TextureInternalFormat::Rg8ui:
				return GL_RG8UI;
				break;
			case Rudy::TextureInternalFormat::Rg16i:
				return GL_RG16I;
				break;
			case Rudy::TextureInternalFormat::Rg16ui:
				return GL_RG16UI;
				break;
			case Rudy::TextureInternalFormat::Rg32i:
				return GL_RG32I;
				break;
			case Rudy::TextureInternalFormat::Rg32ui:
				return GL_RG32UI;
				break;
			case Rudy::TextureInternalFormat::CompressedRgbS3tcDxt1Ext:
				return GL_COMPRESSED_RGB;
				break;
			case Rudy::TextureInternalFormat::CompressedRgbaS3tcDxt1Ext:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedRgbaS3tcDxt3Ext:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedRgbaS3tcDxt5Ext:
				return 0;
				break;
			case Rudy::TextureInternalFormat::RgbIccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::RgbaIccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::AlphaIccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::LuminanceIccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::IntensityIccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::LuminanceAlphaIccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::R5G6B5IccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::R5G6B5A8IccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::Alpha16IccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::Luminance16IccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::Intensity16IccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::Luminance16Alpha8IccSgix:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedAlpha:
				return GL_COMPRESSED_ALPHA;;
				break;
			case Rudy::TextureInternalFormat::CompressedLuminance:
				return GL_COMPRESSED_LUMINANCE;
				break;
			case Rudy::TextureInternalFormat::CompressedLuminanceAlpha:
				return GL_COMPRESSED_LUMINANCE_ALPHA;
				break;
			case Rudy::TextureInternalFormat::CompressedIntensity:
				return GL_COMPRESSED_INTENSITY;
				break;
			case Rudy::TextureInternalFormat::CompressedRgb:
				return GL_COMPRESSED_RGB;
				break;
			case Rudy::TextureInternalFormat::CompressedRgba:
				return GL_COMPRESSED_RGBA;
				break;
			case Rudy::TextureInternalFormat::DepthStencil:
				return GL_DEPTH_STENCIL;
				break;
			case Rudy::TextureInternalFormat::Rgba32f:
				return GL_RGBA32F;
				break;
			case Rudy::TextureInternalFormat::Rgb32f:
				return GL_RGB32F;
				break;
			case Rudy::TextureInternalFormat::Rgba16f:
				return GL_RGBA16F;
				break;
			case Rudy::TextureInternalFormat::Rgb16f:
				return GL_RGB16F;
				break;
			case Rudy::TextureInternalFormat::Depth24Stencil8:
				return GL_DEPTH24_STENCIL8;
				break;
			case Rudy::TextureInternalFormat::R11fG11fB10f:
				return GL_R11F_G11F_B10F;
				break;
			case Rudy::TextureInternalFormat::Rgb9E5:
				return GL_RGB9_E5;
				break;
			case Rudy::TextureInternalFormat::Srgb:
				return GL_SRGB;
				break;
			case Rudy::TextureInternalFormat::Srgb8:
				return GL_SRGB8;
				break;
			case Rudy::TextureInternalFormat::SrgbAlpha:
				return GL_SRGB_ALPHA;
				break;
			case Rudy::TextureInternalFormat::Srgb8Alpha8:
				return GL_SRGB8_ALPHA8;
				break;
			case Rudy::TextureInternalFormat::SluminanceAlpha:
				return GL_SLUMINANCE_ALPHA;
				break;
			case Rudy::TextureInternalFormat::Sluminance8Alpha8:
				return GL_SLUMINANCE8_ALPHA8;
				break;
			case Rudy::TextureInternalFormat::Sluminance:
				return GL_SLUMINANCE;
				break;
			case Rudy::TextureInternalFormat::Sluminance8:
				return GL_SLUMINANCE8;
				break;
			case Rudy::TextureInternalFormat::CompressedSrgb:
				return GL_COMPRESSED_SRGB;
				break;
			case Rudy::TextureInternalFormat::CompressedSrgbAlpha:
				return GL_COMPRESSED_SRGB_ALPHA;
				break;
			case Rudy::TextureInternalFormat::CompressedSluminance:
				return GL_COMPRESSED_SLUMINANCE;
				break;
			case Rudy::TextureInternalFormat::CompressedSluminanceAlpha:
				return GL_COMPRESSED_SLUMINANCE_ALPHA;
				break;
			case Rudy::TextureInternalFormat::CompressedSrgbS3tcDxt1Ext:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedSrgbAlphaS3tcDxt1Ext:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedSrgbAlphaS3tcDxt3Ext:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedSrgbAlphaS3tcDxt5Ext:
				return 0;
				break;
			case Rudy::TextureInternalFormat::DepthComponent32f:
				return GL_DEPTH_COMPONENT32F;
				break;
			case Rudy::TextureInternalFormat::Depth32fStencil8:
				return GL_DEPTH32F_STENCIL8;
				break;
			case Rudy::TextureInternalFormat::Rgba32ui:
				return GL_RGBA32UI;
				break;
			case Rudy::TextureInternalFormat::Rgb32ui:
				return GL_RGB32UI;
				break;
			case Rudy::TextureInternalFormat::Rgba16ui:
				return GL_RGBA16UI;
				break;
			case Rudy::TextureInternalFormat::Rgb16ui:
				return GL_RGB16UI;
				break;
			case Rudy::TextureInternalFormat::Rgba8ui:
				return GL_RGBA8UI;
				break;
			case Rudy::TextureInternalFormat::Rgb8ui:
				return GL_RGB8UI;
				break;
			case Rudy::TextureInternalFormat::Rgba32i:
				return GL_RGBA32I;
				break;
			case Rudy::TextureInternalFormat::Rgb32i:
				return GL_RGB32I;
				break;
			case Rudy::TextureInternalFormat::Rgba16i:
				return GL_RGBA16I;
				break;
			case Rudy::TextureInternalFormat::Rgb16i:
				return GL_RGB16I;
				break;
			case Rudy::TextureInternalFormat::Rgba8i:
				return GL_RGBA8I;
				break;
			case Rudy::TextureInternalFormat::Rgb8i:
				return GL_RGB8I;
				break;
			case Rudy::TextureInternalFormat::Float32UnsignedInt248Rev:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedRedRgtc1:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedSignedRedRgtc1:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedRgRgtc2:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedSignedRgRgtc2:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedRgbaBptcUnorm:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedSrgbAlphaBptcUnorm:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedRgbBptcSignedFloat:
				return 0;
				break;
			case Rudy::TextureInternalFormat::CompressedRgbBptcUnsignedFloat:
				return 0;
				break;
			case Rudy::TextureInternalFormat::R8Snorm:
				return GL_R8_SNORM;
				break;
			case Rudy::TextureInternalFormat::Rg8Snorm:
				return GL_RG8_SNORM;
				break;
			case Rudy::TextureInternalFormat::Rgb8Snorm:
				return GL_RGB8_SNORM;
				break;
			case Rudy::TextureInternalFormat::Rgba8Snorm:
				return GL_RGBA8_SNORM;
				break;
			case Rudy::TextureInternalFormat::R16Snorm:
				return GL_R16_SNORM;
				break;
			case Rudy::TextureInternalFormat::Rg16Snorm:
				return GL_RG16_SNORM;
				break;
			case Rudy::TextureInternalFormat::Rgb16Snorm:
				return GL_RGB16_SNORM;
				break;
			case Rudy::TextureInternalFormat::Rgba16Snorm:
				return GL_RGBA16_SNORM;
				break;
			case Rudy::TextureInternalFormat::Rgb10A2ui:
				return 0;
				break;
			default:
				break;
		}
	}
}