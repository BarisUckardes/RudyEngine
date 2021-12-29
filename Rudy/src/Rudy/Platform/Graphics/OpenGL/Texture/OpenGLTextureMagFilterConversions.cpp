#include "OpenGLTextureMagFilterConversions.h"
#include <GLAD/glad.h>
namespace Rudy
{
    unsigned int OpenGLTextureMagFilterConversions::GetOpenGLMagFilter(TextureMagFilter filter)
    {
		switch (filter)
		{
			case Rudy::TextureMagFilter::Nearest:
				return GL_NEAREST;
				break;
			case Rudy::TextureMagFilter::Linear:
				return GL_LINEAR;
				break;
			default:
				break;
		}
    }
}