#include "OpenGLVertexBuffer.h"
#include <Rudy/Platform/Graphics/OpenGL/Buffer/OpenGLVertexDataTypeConversions.h>
#include <GLAD/glad.h>
namespace Rudy
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(GraphicsDevice* device) : VertexBuffer(device)
	{

	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
	}
	void* OpenGLVertexBuffer::GetNativeHandle() const
	{
		return nullptr;
	}
	void OpenGLVertexBuffer::SetDataCore(const unsigned char* dataPtr, const unsigned int elementSize, const unsigned int elementCount, const VertexLayout& vertexLayout)
	{
		unsigned int vertexArrayID = 0;
		unsigned int vertexBufferID = 0;

		/*
		* Create and bind vertex array
		*/
		glGenVertexArrays(1, &vertexArrayID);
		glBindVertexArray(vertexArrayID);

		/*
		* Create and bind vertex buffer
		*/
		glGenBuffers(1, &vertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

		/*
		* Set buffer data
		*/
		glBufferData(GL_ARRAY_BUFFER, elementSize * elementCount, dataPtr, GL_STATIC_DRAW);

		/*
		* Create vertex array layout
		*/
		unsigned int vertexLayoutIndex = 0;
		Array<VertexLayoutElement> elements = vertexLayout.GetElements();
		for (int i = 0; i < elements.GetCursor(); i++)
		{
            switch (elements[i].DataType)
            {
            case VertexLayoutDataType::None:
                break;
            case VertexLayoutDataType::Float:
            case VertexLayoutDataType::Float2:
            case VertexLayoutDataType::Float3:
            case VertexLayoutDataType::Float4:
                glEnableVertexAttribArray(vertexLayoutIndex);
                glVertexAttribPointer((int)vertexLayoutIndex,
                    (int)elements[i].GetComponentCount(),
                    OpenGLVertexDataTypeConversions::GetOpenGLDataType(elements[i].DataType),
                    elements[i].IsNormalized,
                    (int)vertexLayout.GetStride(),
                    (const void*)elements[i].Offset);
                vertexLayoutIndex++;
                break;
            case VertexLayoutDataType::Mat3:
            case VertexLayoutDataType::Mat4:
			{
                unsigned int count = elements[i].GetComponentCount();
                for (int p = 0; p < count; p++)
                {
                    glEnableVertexAttribArray(vertexLayoutIndex);
                    glVertexAttribPointer((int)vertexLayoutIndex,
                        (int)elements[i].GetComponentCount(),
                        OpenGLVertexDataTypeConversions::GetOpenGLDataType(elements[i].DataType),
                        elements[i].IsNormalized,
                        (int)vertexLayout.GetStride(),
                        (const void*)(elements[i].Offset + sizeof(float) * count * i));
                }
                vertexLayoutIndex++;
			}
                break;
            case VertexLayoutDataType::Int:
                break;
            case VertexLayoutDataType::Int2:
                break;
            case VertexLayoutDataType::Int3:
                break;
            case VertexLayoutDataType::In4:
                break;
            case VertexLayoutDataType::Bool:
                break;
            default:
                break;
            }
		}
	}
}