#include "OpenGLTexture2D.h"
#include <GLAD/glad.h>
#include <Rudy/Platform/Graphics/OpenGL/Texture/OpenGLTextureDataTypeConversions.h>
#include <Rudy/Platform/Graphics/OpenGL/Texture/OpenGLTextureFormatConversions.h>
#include <Rudy/Platform/Graphics/OpenGL/Texture/OpenGLTextureInternalFormatConversions.h>
#include <Rudy/Platform/Graphics/OpenGL/Texture/OpenGLTextureMagFilterConversions.h>
#include <Rudy/Platform/Graphics/OpenGL/Texture/OpenGLTextureMinFilterConversions.h>
#include <Rudy/Platform/Graphics/OpenGL/Texture/OpenGLTextureWrapModeConversions.h>

namespace Rudy
{
	OpenGLTexture2D::OpenGLTexture2D(unsigned int width, unsigned int height,
		TextureFormat format, TextureInternalFormat internalFormat, TextureDataType dataType,
		TextureMinFilter minFilter, TextureMagFilter magFilter,
		TextureWrapMode wrapModeS, TextureWrapMode wrapModeT,
		bool createMipmaps,
		GraphicsDevice* device) : Texture2D(device)
	{
		/*
		* Generate texture id
		*/
		glGenTextures(1, &m_TextureID);

		/*
		* Bind texture
		*/
		glBindTexture(GL_TEXTURE_2D, m_TextureID);

		/*
		* Allocate texture data
		*/
		glTexImage2D(GL_TEXTURE_2D,
			0,
			OpenGLTextureFormatConversions::GetOpenGLTextureFormat(format),
			width, height,
			0,
			OpenGLTextureInternalFormatConversions::GetOpenGLTextureInternalFormat(internalFormat),
			OpenGLTextureDataTypeConversions::GetOpenGLTextureDataType(dataType),
			nullptr);

		/*
		* Set texture parameters
		*/
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, OpenGLTextureWrapModeConversions::GetOpenGLWrapMode(wrapModeS));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, OpenGLTextureWrapModeConversions::GetOpenGLWrapMode(wrapModeT));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, OpenGLTextureMinFilterConversions::GetOpenGLMinFilter(minFilter));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, OpenGLTextureMagFilterConversions::GetOpenGLMagFilter(magFilter));

		/*
		* Unbind texture
		*/
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	OpenGLTexture2D::~OpenGLTexture2D()
	{
	}
	void* OpenGLTexture2D::GetNativeHandle() const
	{
		return (void*)(&m_TextureID);
	}

	void OpenGLTexture2D::SetTextureData(unsigned char* data, unsigned int size)
	{
		/*
		* Bind texture
		*/
		glBindTexture(GL_TEXTURE_2D, m_TextureID);

		/*
		* Set texture data
		*/
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, GetWidth(), GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		/*
		* Set texture parameters
		*/

		/*
		* Unbind texture
		*/
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}