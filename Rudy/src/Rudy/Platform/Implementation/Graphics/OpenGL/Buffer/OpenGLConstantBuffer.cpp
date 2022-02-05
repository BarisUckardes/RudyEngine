#include "OpenGLConstantBuffer.h"
#include <GLAD/glad.h>

namespace Rudy
{
    OpenGLConstantBuffer::OpenGLConstantBuffer(const String& bufferName, unsigned int bufferSize) : ConstantBuffer(bufferName,bufferSize)
    {

    }
    void OpenGLConstantBuffer::SetBufferData(void* dataPtr)
    {
        /*
         * Bind buffer
         */
        glBindBuffer(GL_UNIFORM_BUFFER, m_BufferID);

        /*
        * Allocate buffer
        */
        glBufferData(GL_UNIFORM_BUFFER, GetBufferSize(), dataPtr, GL_STATIC_DRAW);

        /*
        * Unbind buffer
        */
        glBindBuffer(GL_UNIFORM_BUFFER, m_BufferID);
    }
    void OpenGLConstantBuffer::Initialize()
    {
        /*
        * Create buffer
        */
        glGenBuffers(1, &m_BufferID);

        /*
        * Bind buffer
        */
        glBindBuffer(GL_UNIFORM_BUFFER, m_BufferID);

        /*
        * Allocate buffer
        */
        glBufferData(GL_UNIFORM_BUFFER, GetBufferSize(), nullptr, GL_STATIC_DRAW);

        /*
        * Unbind buffer
        */
        glBindBuffer(GL_UNIFORM_BUFFER, m_BufferID);
    }
}