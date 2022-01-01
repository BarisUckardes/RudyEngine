#include "OpenGLCommandBuffer.h"
#include <Rudy/Graphics/Command/RenderCommand.h>
#include <Rudy/Platform/Graphics/OpenGL/Command/Commands/OpenGLClearColorRC.h>
#include <Rudy/Platform/Graphics/OpenGL/Command/Commands/OpenGLSetShaderProgramRC.h>
#include <Rudy/Platform/Graphics/OpenGL/Command/Commands/OpenGLSetVertexBufferRC.h>
#include <Rudy/Platform/Graphics/OpenGL/Command/Commands/OpenGLSetIndexBufferRC.h>
#include <Rudy/Mathematics/Vector2i.h>
#include <Rudy/Graphics/Shader/ShaderProgram.h>
#include <Rudy/Graphics/Buffer/VertexBuffer.h>
#include <Rudy/Graphics/Buffer/IndexBuffer.h>
#include <Rudy/Graphics/Framebuffer/Framebuffer.h>
#include <GLAD/glad.h>
#include <Rudy/Platform/Graphics/OpenGL/Command/Commands/OpenGLSetViewportRC.h>
#include <Rudy/Platform/Graphics/OpenGL/Command/Commands/OpenGLClearDepthRC.h>
#include <Rudy/Platform/Graphics/OpenGL/Command/Commands/OpenGLSetFramebufferRC.h>
#include <Rudy/Platform/Graphics/OpenGL/Command/Commands/OpenGLDrawIndexedRC.h>
namespace Rudy
{
    OpenGLCommandBuffer::~OpenGLCommandBuffer()
    {
        for (int i = 0; i < m_Commands.GetCursor(); i++)
        {
            delete m_Commands[i];
        }
        m_Commands.Clear();
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
        /*
        * Create set shader program command
        */
        OpenGLSetShaderProgramRC* setShaderProgramCommand = new OpenGLSetShaderProgramRC(*(unsigned int*)program->GetNativeHandle());

        /*
        * Register command
        */
        m_Commands.Add(setShaderProgramCommand);

        /*
        * Set last shader program
        */
        m_LastBindShaderProgram = program;
    }
    void OpenGLCommandBuffer::SetVertexBuffer(const VertexBuffer* vertexBuffer)
    {
        /*
        * Create set vertex buffer command
        */
        unsigned int* buffers = (unsigned int*)vertexBuffer->GetNativeHandle();
        OpenGLSetVertexBufferRC* setVertexBufferCommand = new OpenGLSetVertexBufferRC(buffers[0], buffers[1]);

        /*
        * Register command
        */
        m_Commands.Add(setVertexBufferCommand);
    }
    void OpenGLCommandBuffer::SetIndexBuffer(const IndexBuffer* indexBuffer)
    {
        /*
        * Create ser index buffer command
        */
        OpenGLSetIndexBufferRC* setIndexBufferCommand = new OpenGLSetIndexBufferRC(*(unsigned int*)indexBuffer->GetNativeHandle());

        /*
        * Register command
        */
        m_Commands.Add(setIndexBufferCommand);
    }
    void OpenGLCommandBuffer::SetPipelineState(const PipelineState& pipelineState)
    {

    }
    void OpenGLCommandBuffer::SetFramebuffer(const Framebuffer* framebuffer)
    {
        /*
        * Create set frame buffer command
        */
        OpenGLSetFramebufferRC* setFramebufferCommand = new OpenGLSetFramebufferRC(*(unsigned int*)framebuffer->GetNativeHandle());

        /*
        * Register command
        */
        m_Commands.Add(setFramebufferCommand);
    }
    void OpenGLCommandBuffer::SetViewport(const Vector2i& offset,const Vector2i& size)
    {
        /*
        * Create set viewport command
        */
        OpenGLSetViewportRC* setViewportCommand = new OpenGLSetViewportRC(offset, size);

        /*
        * Register command
        */
        m_Commands.Add(setViewportCommand);
    }
    void OpenGLCommandBuffer::SetConstantBuffer(const ConstantBuffer* buffer)
    {

    }
    void OpenGLCommandBuffer::ClearColor(const ColorRgba& color)
    {
        /*
        * Create clear color command
        */
        OpenGLClearColorRC* clearRenderCommand = new OpenGLClearColorRC(color);

        /// <summary>
        /// Register command
        /// </summary>
        /// <param name="color"></param>
        m_Commands.Add(clearRenderCommand);
    }
    void OpenGLCommandBuffer::ClearDepth(float depth)
    {
        /*
        * Create clear depth command
        */
        OpenGLClearDepthRC* clearDepthCommand = new OpenGLClearDepthRC(depth);

        /*
        * Register command
        */
        m_Commands.Add(clearDepthCommand);
    }
    void OpenGLCommandBuffer::DrawIndexed(unsigned int count)
    {
        /*
        * Create draw indexed command
        */
        OpenGLDrawIndexedRC* drawIndexedCommand = new OpenGLDrawIndexedRC(count);

        /*
        * Register command
        */
        m_Commands.Add(drawIndexedCommand);
    }
    void OpenGLCommandBuffer::DrawInstanced()
    {

    }
}