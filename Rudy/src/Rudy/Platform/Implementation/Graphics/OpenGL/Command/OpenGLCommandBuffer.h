#pragma once
#include <Rudy/Graphics/Command/CommandBuffer.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL implementation for the command buffer
	/// </summary>
	class RUDY_API OpenGLCommandBuffer : public CommandBuffer
	{
	public:
		OpenGLCommandBuffer() = default;
		virtual ~OpenGLCommandBuffer() override;

		virtual void* GetNativeHandle() const override;
		virtual void StartRecording() override;
		virtual void FinalizeRecording() override;
		virtual void Execute() override;
		virtual void SetShaderProgram(const ShaderProgram* program) override;
		virtual void SetVertexBuffer(const VertexBuffer* vertexBuffer) override;
		virtual void SetIndexBuffer(const IndexBuffer* indexBuffer) override;
		virtual void SetPipelineState(const PipelineState& pipelineState) override;
		virtual void SetFramebuffer(const Framebuffer* framebuffer) override;
		virtual void SetViewport(const Vector2i& offset,const Vector2i& size) override;
		virtual void SetConstantBuffer(const ConstantBuffer* buffer) override;
		virtual void ClearColor(const ColorRgba& color) override;
		virtual void ClearDepth(float depth) override;
		virtual void DrawIndexed(unsigned int count) override;
		virtual void DrawInstanced() override;

	private:
		Array<RenderCommand*> m_Commands;
		const ShaderProgram* m_LastBindShaderProgram;
		unsigned int m_CurrentTextureSlot;
		bool m_Recording;
	};

}
