#include "OpenGLShaderStageConversions.h"
#include <GLAD/glad.h>
namespace Rudy
{
    unsigned int OpenGLShaderStageConversions::GetOpenGLShaderStage(ShaderStage stage)
    {
		switch (stage)
		{
			case ShaderStage::None:
				return GL_NONE;
				break;
			case ShaderStage::Vertex:
				return GL_VERTEX_SHADER;
				break;
			case ShaderStage::Fragment:
				return GL_FRAGMENT_SHADER;
				break;
			case ShaderStage::Geometry:
				return GL_GEOMETRY_SHADER;
				break;
			default:
				break;
		}
    }
}