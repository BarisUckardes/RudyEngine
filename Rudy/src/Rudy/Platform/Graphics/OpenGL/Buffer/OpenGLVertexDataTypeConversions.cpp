#include "OpenGLVertexDataTypeConversions.h"
#include <GLAD/glad.h>
namespace Rudy
{
	unsigned int OpenGLVertexDataTypeConversions::GetOpenGLDataType(VertexLayoutDataType dataType)
	{
        switch (dataType)
        {
            case VertexLayoutDataType::None:
                return GL_BYTE;
                break;
            case VertexLayoutDataType::Float:
            case VertexLayoutDataType::Float2:
            case VertexLayoutDataType::Float3:
            case VertexLayoutDataType::Float4:
            case VertexLayoutDataType::Mat3:
            case VertexLayoutDataType::Mat4:
                return GL_FLOAT;
                break;
            case VertexLayoutDataType::Int:
            case VertexLayoutDataType::Int2:
            case VertexLayoutDataType::Int3:
            case VertexLayoutDataType::In4:
                return GL_INT;
                break;
            case VertexLayoutDataType::Bool:
                return GL_BYTE;
                break;
            default:
                return GL_BYTE;
                break;
        }
	}
}