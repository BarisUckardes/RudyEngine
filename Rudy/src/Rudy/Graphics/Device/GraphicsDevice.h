#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Platform/Implementation/Graphics/GraphicsAPIType.h>
#include <Rudy/Graphics/Texture/TextureFormat.h>
#include <Rudy/Graphics/Texture/TextureInternalFormat.h>
#include <Rudy/Graphics/Texture/TextureDataType.h>
#include <Rudy/Graphics/Texture/TextureMagFilter.h>
#include <Rudy/Graphics/Texture/TextureMinFilter.h>
#include <Rudy/Graphics/Texture/TextureWrapMode.h>
#include <Rudy/Graphics/Shader/Shader.h>
namespace Rudy
{
	/*
	* Forward declerations
	*/
	class PlatformWindow;
	class IndexBuffer;
	class VertexBuffer;
	class CommandBuffer;
	class ConstantBuffer;
	class Texture2D;
	class Shader;
	class ShaderProgram;
	class GraphicsDeviceObject;
	class String;
	class Framebuffer;

	/// <summary>
	/// Graphics api-agnostic graphics device class
	/// </summary>
	class RUDY_API GraphicsDevice
	{
	public:
		GraphicsDevice() = default;
		~GraphicsDevice();

		/// <summary>
		/// Creates platform-agnostic graphics device implementation
		/// </summary>
		/// <param name="preferredAPIType"></param>
		/// <returns></returns>
		static GraphicsDevice* Create(PlatformWindow* window,GraphicsAPIType preferredAPIType);

		/// <summary>
		/// Returns whether this graphics device targets a window or just a headless graphics device
		/// </summary>
		/// <returns></returns>
		bool HasTargetWindow() const;

		/// <summary>
		/// Returns the target window.(if has one)
		/// </summary>
		/// <returns></returns>
		PlatformWindow* GetTargetWindow() const;

		/// <summary>
		/// Returns the api type for this graphics device
		/// </summary>
		/// <returns></returns>
		GraphicsAPIType GetApiType() const;

		/// <summary>
		/// Initializes this graphics device
		/// </summary>
		/// <param name="window"></param>
		void Initialize(PlatformWindow* window);

		/// <summary>
		/// Creates a command buffer using this device
		/// </summary>
		/// <returns></returns>
		virtual CommandBuffer* CreateCommandBuffer() = 0;

		/// <summary>
		/// Creates an index buffer using this device
		/// </summary>
		/// <returns></returns>
		virtual IndexBuffer* CreateIndexBuffer() = 0;

		/// <summary>
		/// Creates a vertex buffer
		/// </summary>
		/// <returns></returns>
		virtual VertexBuffer* CreateVertexBuffer() = 0;

		/// <summary>
		/// Creates a constant buffer
		/// </summary>
		/// <returns></returns>
		virtual ConstantBuffer* CreateConstantBuffer(const String& bufferName, unsigned int bufferSize) = 0;

		/// <summary>
		/// Creates a texture2D
		/// </summary>
		/// <returns></returns>
		virtual Texture2D* CreateTexture2D() = 0;

		/// <summary>
		/// Creates a shader
		/// </summary>
		/// <param name="stage"></param>
		/// <returns></returns>
		virtual Shader* CreateShader(ShaderStage stage) = 0;

		/// <summary>
		/// Creates a shader program
		/// </summary>
		/// <param name="shaders"></param>
		/// <returns></returns>
		virtual ShaderProgram* CreateShaderProgram() = 0;

		/// <summary>
		/// Creates a framebuffer
		/// </summary>
		/// <returns></returns>
		virtual Framebuffer* CreateFramebuffer() = 0;

		/// <summary>
		/// Swaps the render buffers of the window
		/// </summary>
		virtual void Swapbuffers() = 0;
	protected:
		/// <summary>
		/// Sets the api type for this device
		/// </summary>
		/// <param name="apiType"></param>
		void SetApiType(GraphicsAPIType apiType);

		/// <summary>
		/// Sets a target device object for a graphicsDeviceObject 
		/// </summary>
		/// <param name="deviceObject"></param>
		void SetDeviceObjectTargetDevice(GraphicsDeviceObject* deviceObject);

		/// <summary>
		/// Graphics api implementation of the initialization
		/// </summary>
		virtual void InitializeCore() = 0;
	private:
		GraphicsAPIType m_APIType;
		PlatformWindow* m_TargetWindow;
	};
}