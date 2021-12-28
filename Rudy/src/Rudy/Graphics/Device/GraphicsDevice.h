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

		GraphicsDevice(Window* targetWindow);

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
		virtual Texture2D* CreateTexture2D(unsigned int width, unsigned int height,
			TextureFormat format, TextureInternalFormat internalFormat, TextureDataType dataType,
			TextureMinFilter minFilter, TextureMagFilter magFilter,
			TextureWrapMode wrapModeS, TextureWrapMode wrapModeT,
			bool createMipmaps) = 0;

		/// <summary>
		/// Swaps the render buffers of the window
		/// </summary>
		virtual void Swapbuffers() = 0;

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
	protected:
		~GraphicsDevice();

		/// <summary>
		/// Sets the api type for this device
		/// </summary>
		/// <param name="apiType"></param>
		void SetApiType(GraphicsAPIType apiType);
	private:
		GraphicsAPIType m_APIType;
		Window* m_TargetWindow;
	};
}