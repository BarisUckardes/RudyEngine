#include "OpenGLCommandBuffer.h"
#include <Rudy/Graphics/Command/RenderCommand.h>
namespace Rudy
{
    OpenGLCommandBuffer::OpenGLCommandBuffer(GraphicsDevice* device) : CommandBuffer(device)
    {

    }
    OpenGLCommandBuffer::~OpenGLCommandBuffer()
    {

    }

    void* OpenGLCommandBuffer::GetNativeHandle() const
    {
        return nullptr;
    }
    void OpenGLCommandBuffer::StartRecording()
    {
        m_Recording = true;
    }
    void OpenGLCommandBuffer::FinalizeRecording()
    {
        m_Recording = false;
    }
    void OpenGLCommandBuffer::Execute()
    {
        /*
        * Render each command
        */
        for (unsigned int i = 0; i < m_Commands.GetCursor(); i++)
        {
            m_Commands[i]->Execute();
        }
    }
    void OpenGLCommandBuffer::SetShaderProgram(const ShaderProgram* program)
    {

    }
    void OpenGLCommandBuffer::SetVertexBuffer(const VertexBuffer* vertexBuffer)
    {

    }
    void OpenGLCommandBuffer::SetIndexBuffer(const IndexBuffer* indexBuffer)
    {

    }
    void OpenGLCommandBuffer::SetPipelineState(const PipelineState& pipelineState)
    {

    }
    void OpenGLCommandBuffer::SetFramebuffer2D(const Framebuffer2D* framebuffer)
    {

    }
    void OpenGLCommandBuffer::SetViewport(const Vector2i& size)
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterFloat(float value)
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterFloatArray(const Array<float>& values)
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterInteger(int value)
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterIntegerArray(const Array<int>& values)
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterVector2(const Vector2f& value)
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterVector2Array(const Array<Vector2f>& values)
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterVector3(const Vector3f& value)
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterVector3Array(const Array<Vector3f>& values)
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterVector4()
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterVector4Array()
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterTexture2D(const Texture2D* value)
    {

    }
    void OpenGLCommandBuffer::SetProgramParameterTexture2DArray(const Array<Texture2D*>& values)
    {

    }
    void OpenGLCommandBuffer::ClearColor()
    {

    }
    void OpenGLCommandBuffer::ClearDepth(float depth)
    {

    }
    void OpenGLCommandBuffer::DrawIndexed()
    {

    }
    void OpenGLCommandBuffer::DrawInstanced()
    {

    }
}