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
		~OpenGLCommandBuffer() = default;

		virtual void* GetNativeHandle() const override;
		virtual void StartRecording() override;
		virtual void FinalizeRecording() override;
		virtual void Execute() override;
		virtual void SetShaderProgram(const ShaderProgram* program) override;
		virtual void SetVertexBuffer(const VertexBuffer* vertexBuffer) override;
		virtual void SetIndexBuffer(const IndexBuffer* indexBuffer) override;
		virtual void SetPipelineState(const PipelineState& pipelineState) override;
		virtual void SetFramebuffer2D(const Framebuffer2D* framebuffer) override;
		virtual void SetViewport(const Vector2i& size) override;
		virtual void SetProgramParameterFloat(float value) override;
		virtual void SetProgramParameterFloatArray(const Array<float>& values) override;
		virtual void SetProgramParameterInteger(int value) override;
		virtual void SetProgramParameterIntegerArray(const Array<int>& values) override;
		virtual void SetProgramParameterVector2(const Vector2f& value) override;
		virtual void SetProgramParameterVector2Array(const Array<Vector2f>& values) override;
		virtual void SetProgramParameterVector3(const Vector3f& value) override;
		virtual void SetProgramParameterVector3Array(const Array<Vector3f>& values) override;
		virtual void SetProgramParameterVector4() override;
		virtual void SetProgramParameterVector4Array() override;
		virtual void SetProgramParameterTexture2D(const Texture2D* value) override;
		virtual void SetProgramParameterTexture2DArray(const Array<Texture2D*>& values) override;
		virtual void ClearColor() override;
		virtual void ClearDepth(float depth) override;
		virtual void DrawIndexed() override;
		virtual void DrawInstanced() override;

	private:
		Array<RenderCommand*> m_Commands;
		unsigned int m_CurrentTextureSlot;
		bool m_Recording;
	};

}
