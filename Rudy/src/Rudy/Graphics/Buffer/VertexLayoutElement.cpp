#include "VertexLayoutElement.h"

namespace Rudy
{
    VertexLayoutElement::VertexLayoutElement(VertexLayoutDataType dataType, const String& name, bool isNormalized)
    {
        DataType = dataType;
        Name = name;
        IsNormalized = isNormalized;
    }
    unsigned int VertexLayoutElement::GetComponentCount() const
	{
        switch (DataType)
        {
            case VertexLayoutDataType::None:
                return 0;
                break;
            case VertexLayoutDataType::Float:
                return 1;
                break;
            case VertexLayoutDataType::Float2:
                return 2;
                break;
            case VertexLayoutDataType::Float3:
                return 3;
                break;
            case VertexLayoutDataType::Float4:
                return 4;
                break;
            case VertexLayoutDataType::Mat3:
                return 3;
                break;
            case VertexLayoutDataType::Mat4:
                return 4;
                break;
            case VertexLayoutDataType::Int:
                return 1;
                break;
            case VertexLayoutDataType::Int2:
                return 2;
                break;
            case VertexLayoutDataType::Int3:
                return 3;
                break;
            case VertexLayoutDataType::In4:
                return 4;
                break;
            case VertexLayoutDataType::Bool:
                return 1;
                break;
            default:
                return 0;
                break;
        }
	}
}