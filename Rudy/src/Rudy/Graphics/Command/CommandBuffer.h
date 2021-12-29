#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{
	class RenderCommand;
	class RUDY_API CommandBuffer : public GraphicsDeviceObject
	{
	public:
		void StartRecording();
		void FinalizeRecording();
		void Execute();

		virtual void SetShaderProgram() = 0;
		virtual void SetVertexBuffer() = 0;
		virtual void SetIndexBuffer() = 0;
		virtual void SetPipelineState() = 0;
		virtual void SetFramebuffer() = 0;
		virtual void SetViewport() = 0;

		virtual void SetProgramParameterFloat() = 0;
		virtual void SetProgramParameterFloatArray() = 0;
		virtual void SetProgramParameterInteger() = 0;
		virtual void SetProgramParameterIntegerArray() = 0;
		virtual void SetProgramParameterVector2() = 0;
		virtual void SetProgramParameterVector2Array() = 0;
		virtual void SetProgramParameterVector3() = 0;
		virtual void SetProgramParameterVector3Array() = 0;
		virtual void SetProgramParameterVector4() = 0;
		virtual void SetProgramParameterVector4Array() = 0;
		virtual void SetProgramParameterTexture2D() = 0;
		virtual void SetProgramParameterTexture2DArray() = 0;
		
		virtual void ClearColor() = 0;
		virtual void ClearDepth() = 0;
		
		virtual void DrawIndexed() = 0;
		virtual void DrawInstanced() = 0;
	protected:
		CommandBuffer(GraphicsDevice* device);
		virtual ~CommandBuffer() = default;
	private:
		Array<RenderCommand*> m_Commands;
		unsigned int m_ActiveTextureSlots;
		bool m_Recording;
	};
}