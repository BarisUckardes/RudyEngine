#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{

	class RenderCommand;
	class ShaderProgram;
	class VertexBuffer;
	class IndexBuffer;
	class Framebuffer2D;
	class Texture2D;
	struct PipelineState;
	struct Vector2i;
	struct Vector2f;
	struct Vector3f;

	/// <summary>
	/// A device object which records render commands
	/// </summary>
	class RUDY_API CommandBuffer : public GraphicsDeviceObject
	{
	public:

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
		virtual void SetFramebuffer2D(const Framebuffer2D* framebuffer) = 0;

		/// <summary>
		/// Sets the rendering rect aka viewport
		/// </summary>
		virtual void SetViewport(const Vector2i& size) = 0;

		/// <summary>
		/// Sets a flaot parameter for the shader program
		/// </summary>
		/// <param name="value"></param>
		virtual void SetProgramParameterFloat(float value) = 0;

		/// <summary>
		/// Sets a float array parameter for the shader program
		/// </summary>
		/// <param name="values"></param>
		virtual void SetProgramParameterFloatArray(const Array<float>& values) = 0;

		/// <summary>
		/// Sets an integer parameter for the shader program
		/// </summary>
		/// <param name="value"></param>
		virtual void SetProgramParameterInteger(int value) = 0;

		/// <summary>
		/// Sets a integer array parameters for the shader program
		/// </summary>
		/// <param name="values"></param>
		virtual void SetProgramParameterIntegerArray(const Array<int>& values) = 0;

		/// <summary>
		/// Sets a vector2 parameter for the shader program
		/// </summary>
		/// <param name="value"></param>
		virtual void SetProgramParameterVector2(const Vector2f& value) = 0;

		/// <summary>
		/// Sets a vector2 array parameter for the shader program
		/// </summary>
		/// <param name="values"></param>
		virtual void SetProgramParameterVector2Array(const Array<Vector2f>& values) = 0;

		/// <summary>
		/// Sets a vector3 parameter for the shader program
		/// </summary>
		/// <param name="value"></param>
		virtual void SetProgramParameterVector3(const Vector3f& value) = 0;

		/// <summary>
		/// Sets a vector3 array parameter for the shader program
		/// </summary>
		/// <param name="values"></param>
		virtual void SetProgramParameterVector3Array(const Array<Vector3f>& values) = 0;

		/// <summary>
		/// Sets a vector4 parameter for the shader program
		/// </summary>
		virtual void SetProgramParameterVector4() = 0;

		/// <summary>
		/// Sets a vector4 array parameter for the shader program
		/// </summary>
		virtual void SetProgramParameterVector4Array() = 0;

		/// <summary>
		/// Sets a texture2D parameter for the shader program
		/// </summary>
		/// <param name="value"></param>
		virtual void SetProgramParameterTexture2D(const Texture2D* value) = 0;

		/// <summary>
		/// Sets a texture2D array parameter for the shader program
		/// </summary>
		/// <param name="values"></param>
		virtual void SetProgramParameterTexture2DArray(const Array<Texture2D*>& values) = 0;
		
		/// <summary>
		/// Clears the color of the current framebuffer
		/// </summary>
		virtual void ClearColor() = 0;

		/// <summary>
		/// Clears the depth value of the current framebuffer
		/// </summary>
		/// <param name="depth"></param>
		virtual void ClearDepth(float depth) = 0;
		
		/// <summary>
		/// Issues an indexed draw call
		/// </summary>
		virtual void DrawIndexed() = 0;

		/// <summary>
		/// Issues an instanced draw call
		/// </summary>
		virtual void DrawInstanced() = 0;
	protected:
		CommandBuffer(GraphicsDevice* device);
		virtual ~CommandBuffer() = default;
	};
}