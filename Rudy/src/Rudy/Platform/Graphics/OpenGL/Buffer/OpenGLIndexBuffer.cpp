#include "OpenGLIndexBuffer.h"
#include <GLAD/glad.h>
namespace Rudy
{
    OpenGLIndexBuffer::OpenGLIndexBuffer(GraphicsDevice* ownerDevice) : IndexBuffer(ownerDevice)
    {

    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        /*
        * Delete index buffer
        */
    }

    void* OpenGLIndexBuffer::GetNativeHandle() const
    {
        return (void*)&m_IndexBufferID;
    }

    void OpenGLIndexBuffer::SetDataCore(unsigned char* dataPtr, unsigned int count, unsigned int sizePerElement)
    {
        /*
        * Delete former index buffer state
        */

        /*
        * Generate new handle and bind it
        */
        glGenBuffers(1, &m_IndexBufferID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);

        /*
        * Set buffer data
        */
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizePerElement, dataPtr, GL_STATIC_DRAW);

        /*
        * Unbind
        */
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);

    }
}
