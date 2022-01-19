#pragma once
#include <Rudy/Graphics/Texture/Texture2D.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL implementation of a texture2D
	/// </summary>
	class RUDY_API OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D() = default;
		~OpenGLTexture2D() = default;


		virtual void* GetNativeHandle() const override;
		virtual void SetTextureData(unsigned char* data, unsigned int size) override;
		virtual void Initialize(unsigned int width, unsigned int height,
			TextureFormat format, TextureInternalFormat internalFormat, TextureDataType dataType,
			TextureMinFilter minFilter, TextureMagFilter magFilter,
			TextureWrapMode wrapModeS, TextureWrapMode wrapModeT,
			bool createMipmaps) override;
	protected:
		virtual void FreeDeviceObjectCore() override;
	private:
		unsigned int m_TextureID;
	};

}
