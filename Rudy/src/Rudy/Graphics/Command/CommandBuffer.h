#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{
	/*
	* Forward declarations
	*/
	class RenderCommand;
	class ShaderProgram;
	class VertexBuffer;
	class IndexBuffer;
	class ConstantBuffer;
	class Framebuffer;
	class Texture2D;
	struct PipelineState;
	struct Vector2i;
	struct Vector2f;
	struct Vector3f;
	struct ColorRgba;

	/// <summary>
	/// A device object which records render commands
	/// </summary>
	class RUDY_API CommandBuffer : public GraphicsDeviceObject
	{
	public:
		CommandBuffer() = default;
		virtual ~CommandBuffer() = 0;

		/// <summary>
		/// Starts the recording of the commands
		/// </summary>
		virtual void StartRecording() = 0;

		/// <summary>
		/// Finishes the recording of the commands
		/// </summary>
		virtual void FinalizeRecording() = 0;

		/// <summary>
		/// Executes the commands
		/// </summary>
		virtual void Execute() = 0;

		/// <summary>
		/// Sets a shader program 
		/// </summary>
		/// <param name="program"></param>
		virtual void SetShaderProgram(const ShaderProgram* program) = 0;

		/// <summary>
		/// Sets a vertex buffer
		/// </summary>
		/// <param name="vertexBuffer"></param>
		virtual void SetVertexBuffer(const VertexBuffer* vertexBuffer) = 0;

		/// <summary>
		/// Sets an index buffer
		/// </summary>
		/// <param name="indexBuffer"></param>
		virtual void SetIndexBuffer(const IndexBuffer* indexBuffer) = 0;

		/// <summary>
		/// Sets the current pipeline state
		/// </summary>
		/// <param name="pipelineState"></param>
		virtual void SetPipelineState(const PipelineState& pipelineState) = 0;

		/// <summary>
		/// Sets a framebuffer2D
		/// </summary>
		/// <param name="framebuffer"></param>
		virtual void SetFramebuffer(const Framebuffer* framebuffer) = 0;

		/// <summary>
		/// Sets the rendering rect aka viewport
		/// </summary>
		virtual void SetViewport(const Vector2i& offset,const Vector2i& size) = 0;

		/// <summary>
		/// Sets a constant buffer for the current program
		/// </summary>
		/// <param name="buffer"></param>
		virtual void SetConstantBuffer(const ConstantBuffer* buffer) = 0;
		
		/// <summary>
		/// Clears the color of the current framebuffer
		/// </summary>
		virtual void ClearColor(const ColorRgba& color) = 0;

		/// <summary>
		/// Clears the depth value of the current framebuffer
		/// </summary>
		/// <param name="depth"></param>
		virtual void ClearDepth(float depth) = 0;
		
		/// <summary>
		/// Issues an indexed draw call
		/// </summary>
		virtual void DrawIndexed(unsigned int count) = 0;

		/// <summary>
		/// Issues an instanced draw call
		/// </summary>
		virtual void DrawInstanced() = 0;
	};
}