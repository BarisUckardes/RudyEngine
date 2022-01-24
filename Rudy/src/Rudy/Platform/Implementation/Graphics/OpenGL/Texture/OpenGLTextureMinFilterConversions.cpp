#include "OpenGLTextureMinFilterConversions.h"
#include <GLAD/glad.h>
#include <stdio.h>
namespace Rudy
{
    unsigned int OpenGLTextureMinFilterConversions::GetOpenGLMinFilter(TextureMinFilter filter)
    {
		switch (filter)
		{
			case Rudy::TextureMinFilter::Nearest:
				return GL_NEAREST;
				break;
			case Rudy::TextureMinFilter::Linear:
				return GL_LINEAR;
				break;
			case Rudy::TextureMinFilter::NearestMipmapNearest:
				return GL_NEAREST_MIPMAP_NEAREST;
				break;
			case Rudy::TextureMinFilter::LinearMimpmapNearest:
				return GL_LINEAR_MIPMAP_NEAREST;
				break;
			case Rudy::TextureMinFilter::NearestMippmapLinear:
				return GL_NEAREST_MIPMAP_LINEAR;
				break;
			case Rudy::TextureMinFilter::LinearMipmapLinear:
				return GL_LINEAR_MIPMAP_LINEAR;
				break;
			default:
				break;
		}
    }
}