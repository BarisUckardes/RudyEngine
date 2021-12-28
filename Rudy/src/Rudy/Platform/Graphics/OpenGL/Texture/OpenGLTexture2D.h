#pragma once
#include <Rudy/Graphics/Texture/Texture2D.h>

namespace Rudy
{
	class RUDY_API OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(unsigned int width, unsigned int height,
			TextureFormat format, TextureInternalFormat internalFormat, TextureDataType dataType,
			TextureMinFilter minFilter, TextureMagFilter magFilter,
			TextureWrapMode wrapModeS, TextureWrapMode wrapModeT,
			bool createMipmaps,
			GraphicsDevice* device);
		virtual ~OpenGLTexture2D() override;


		virtual void* GetNativeHandle() const override;
		virtual void SetTextureData(unsigned char* data, unsigned int size) override;
	private:
		unsigned int m_TextureID;
	};

}
