#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Platform/Graphics/GraphicsAPIType.h>
#include <Rudy/Graphics/Texture/TextureFormat.h>
#include <Rudy/Graphics/Texture/TextureInternalFormat.h>
#include <Rudy/Graphics/Texture/TextureDataType.h>
#include <Rudy/Graphics/Texture/TextureMagFilter.h>
#include <Rudy/Graphics/Texture/TextureMinFilter.h>
#include <Rudy/Graphics/Texture/TextureWrapMode.h>

namespace Rudy
{
	class Window;
	class IndexBuffer;
	class VertexBuffer;
	class CommandBuffer;
	class Texture2D;
	class GraphicsDeviceObject;

	/// <summary>
	/// Graphics api-agnostic graphics device class
	/// </summary>
	class RUDY_API GraphicsDevice
	{
	public:
		/// <summary>
		/// Creates platform-agnostic graphics device implementation
		/// </summary>
		/// <param name="preferredAPIType"></param>
		/// <returns></returns>
		static GraphicsDevice* Create(Window* window,GraphicsAPIType preferredAPIType);

		/// <summary>
		/// Returns whether this graphics device targets a window or just a headless graphics device
		/// </summary>
		/// <returns></returns>
		bool HasTargetWindow() const;

		/// <summary>
		/// Returns the target window.(if has one)
		/// </summary>
		/// <returns></returns>
		Window* GetTargetWindow() const;

		/// <summary>
		/// Returns the api type for this graphics device
		/// </summary>
		/// <returns></returns>
		GraphicsAPIType GetApiType() const;

		/// <summary>
		/// Initializes this graphics device
		/// </summary>
		/// <param name="window"></param>
		void Initialize(Window* window);

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
		/// Creates a texture2D
		/// </summary>
		/// <returns></returns>
		virtual Texture2D* CreateTexture2D() = 0;

		/// <summary>
		/// Swaps the render buffers of the window
		/// </summary>
		virtual void Swapbuffers() = 0;
	protected:
		GraphicsDevice() = default;
		~GraphicsDevice();

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
		Window* m_TargetWindow;
	};
}