#include "OpenGLTextureFormatConversions.h"
#include <GLAD/glad.h>
#include <stdio.h>
namespace Rudy
{
    unsigned int OpenGLTextureFormatConversions::GetOpenGLTextureFormat(TextureFormat format)
    {
		switch (format)
		{
			case Rudy::TextureFormat::None:
				return 0;
				break;
			case Rudy::TextureFormat::UnsignedShort:
				return GL_UNSIGNED_SHORT;
				break;
			case Rudy::TextureFormat::UnsignedInt:
				return GL_UNSIGNED_INT;
				break;
			case Rudy::TextureFormat::ColorIndex:
				return GL_COLOR_INDEX;
				break;
			case Rudy::TextureFormat::StencilIndex:
				return GL_STENCIL_INDEX;
				break;
			case Rudy::TextureFormat::DepthComponent:
				return GL_DEPTH_COMPONENT;
				break;
			case Rudy::TextureFormat::Red:
				return GL_RED;
				break;
			case Rudy::TextureFormat::RedExt:
				return GL_RED;
				break;
			case Rudy::TextureFormat::Green:
				return GL_GREEN;
				break;
			case Rudy::TextureFormat::Blue:
				return GL_BLUE;
				break;
			case Rudy::TextureFormat::Alpha:
				return GL_ALPHA;
				break;
			case Rudy::TextureFormat::Rgb:
				return GL_RGB;
				break;
			case Rudy::TextureFormat::Rgba:
				return GL_RGBA;
				break;
			case Rudy::TextureFormat::Luminance:
				return GL_LUMINANCE;
				break;
			case Rudy::TextureFormat::LuminanceAlpha:
				return GL_LUMINANCE_ALPHA;
				break;
			case Rudy::TextureFormat::AbgrExt:
				return 0;
				break;
			case Rudy::TextureFormat::CmykExt:
				return 0;
				break;
			case Rudy::TextureFormat::CmykaExt:
				return 0;
				break;
			case Rudy::TextureFormat::Bgr:
				return GL_BGR;
				break;
			case Rudy::TextureFormat::Bgra:
				return GL_BGRA;
				break;
			case Rudy::TextureFormat::Ycrcb422Sgix:
				return 0;
				break;
			case Rudy::TextureFormat::Ycrcb444Sgix:
				return 0;
				break;
			case Rudy::TextureFormat::Rg:
				return GL_RG;
				break;
			case Rudy::TextureFormat::RgInteger:
				return GL_RG_INTEGER;
				break;
			case Rudy::TextureFormat::R5G6B5IccSgix:
				return 0;
				break;
			case Rudy::TextureFormat::R5G6B5A8IccSgix:
				return 0;
				break;
			case Rudy::TextureFormat::Alpha16IccSgix:
				return 0;
				break;
			case Rudy::TextureFormat::Luminance16IccSgix:
				return 0;
				break;
			case Rudy::TextureFormat::Luminance16Alpha8IccSgix:
				return 0;
				break;
			case Rudy::TextureFormat::DepthStencil:
				return GL_DEPTH_STENCIL;
				break;
			case Rudy::TextureFormat::RedInteger:
				return GL_RED_INTEGER;
				break;
			case Rudy::TextureFormat::GreenInteger:
				return GL_GREEN_INTEGER;
				break;
			case Rudy::TextureFormat::BlueInteger:
				return GL_BLUE_INTEGER;
				break;
			case Rudy::TextureFormat::AlphaInteger:
				return GL_ALPHA_INTEGER;
				break;
			case Rudy::TextureFormat::RgbInteger:
				return GL_RGB_INTEGER;
				break;
			case Rudy::TextureFormat::RgbaInteger:
				return GL_RGBA_INTEGER;
				break;
			case Rudy::TextureFormat::BgrInteger:
				return GL_BGR_INTEGER;
				break;
			case Rudy::TextureFormat::BgraInteger:
				return GL_BGRA_INTEGER;
				break;
			default:
				break;
		}
    }
}