#include "VertexLayoutElement.h"

namespace Rudy
{
    unsigned int GetVertexLayoutDataTypeSize(VertexLayoutDataType type)
    {
        switch (type)
        {
        case Rudy::VertexLayoutDataType::None:
            return 0;
            break;
        case Rudy::VertexLayoutDataType::Float:
            return 4;
            break;
        case Rudy::VertexLayoutDataType::Float2:
            return 4 * 2;
            break;
        case Rudy::VertexLayoutDataType::Float3:
            return 4 * 3;
            break;
        case Rudy::VertexLayoutDataType::Float4:
            return 4 * 4;
            break;
        case Rudy::VertexLayoutDataType::Mat3:
            return 4 * 3 * 3;
            break;
        case Rudy::VertexLayoutDataType::Mat4:
            return 4 * 4 * 4;
            break;
        case Rudy::VertexLayoutDataType::Int:
            return 4;
            break;
        case Rudy::VertexLayoutDataType::Int2:
            return 4 * 2;
            break;
        case Rudy::VertexLayoutDataType::Int3:
            return 4 * 3;
            break;
        case Rudy::VertexLayoutDataType::In4:
            return 4 * 4;
            break;
        case Rudy::VertexLayoutDataType::Bool:
            return 1;
            break;
        default:
            break;
        }
    }

    VertexLayoutElement::VertexLayoutElement(VertexLayoutDataType dataType, const String& name, bool isNormalized)
    {
        DataType = dataType;
        Name = name;
        IsNormalized = isNormalized;
        Size = GetVertexLayoutDataTypeSize(dataType);
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