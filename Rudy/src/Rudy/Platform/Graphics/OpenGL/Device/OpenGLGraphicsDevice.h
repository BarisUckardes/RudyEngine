#pragma once
#include <Rudy/Graphics/Device/GraphicsDevice.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL implementation of graphics device
	/// </summary>
	class RUDY_API OpenGLGraphicsDevice : public GraphicsDevice
	{
	public:
		OpenGLGraphicsDevice(Window* targetWindow);
		~OpenGLGraphicsDevice() = default;

		virtual void Swapbuffers() override;

		virtual IndexBuffer* CreateIndexBuffer() override;
		virtual VertexBuffer* CreateVertexBuffer() override;
		virtual Texture2D* CreateTexture2D(unsigned int width, unsigned int height,
			TextureFormat format, TextureInternalFormat internalFormat, TextureDataType dataType,
			TextureMinFilter minFilter, TextureMagFilter magFilter,
			TextureWrapMode wrapModeS, TextureWrapMode wrapModeT,
			bool createMipmaps) override;
		virtual CommandBuffer* CreateCommandBuffer() override;

	};


}