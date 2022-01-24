#include "OpenGLTextureWrapModeConversions.h"
#include <GLAD/glad.h>
#include <stdio.h>
namespace Rudy
{
    unsigned int OpenGLTextureWrapModeConversions::GetOpenGLWrapMode(TextureWrapMode wrapMode)
    {
		switch (wrapMode)
		{
			case Rudy::TextureWrapMode::Clamp:
				return GL_CLAMP;
				break;
			case Rudy::TextureWrapMode::ClampToEdge:
				return GL_CLAMP_TO_EDGE;
				break;
			case Rudy::TextureWrapMode::ClampToBorder:
				return GL_CLAMP_TO_BORDER;
				break;
			case Rudy::TextureWrapMode::Repeat:
				return GL_REPEAT;
				break;
			case Rudy::TextureWrapMode::Mirror:
				return GL_MIRRORED_REPEAT;
				break;
			default:
				break;
		}
    }
}