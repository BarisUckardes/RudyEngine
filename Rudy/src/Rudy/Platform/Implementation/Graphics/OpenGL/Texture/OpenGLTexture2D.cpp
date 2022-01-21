#include "OpenGLTexture2D.h"
#include <GLAD/glad.h>
#include <Rudy/Platform/Implementation/Graphics/OpenGL/Texture/OpenGLTextureDataTypeConversions.h>
#include <Rudy/Platform/Implementation/Graphics/OpenGL/Texture/OpenGLTextureFormatConversions.h>
#include <Rudy/Platform/Implementation/Graphics/OpenGL/Texture/OpenGLTextureInternalFormatConversions.h>
#include <Rudy/Platform/Implementation/Graphics/OpenGL/Texture/OpenGLTextureMagFilterConversions.h>
#include <Rudy/Platform/Implementation/Graphics/OpenGL/Texture/OpenGLTextureMinFilterConversions.h>
#include <Rudy/Platform/Implementation/Graphics/OpenGL/Texture/OpenGLTextureWrapModeConversions.h>
#include <stdio.h>

namespace Rudy
{
	
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
		glTexImage2D(GL_TEXTURE_2D, 0,
			OpenGLTextureInternalFormatConversions::GetOpenGLTextureInternalFormat(GetTextureInternalFormat()),
			GetWidth(), GetHeight(),
			0,
			OpenGLTextureFormatConversions::GetOpenGLTextureFormat(GetTextureFormat()),
			OpenGLTextureDataTypeConversions::GetOpenGLTextureDataType(GetTextureDataType()),
			data);

		/*
		* Set texture parameters
		*/
	/*	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, OpenGLTextureWrapModeConversions::GetOpenGLWrapMode(GetWrapModeS()));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, OpenGLTextureWrapModeConversions::GetOpenGLWrapMode(GetWrapModeT()));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, OpenGLTextureMinFilterConversions::GetOpenGLMinFilter(GetMinFilter()));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, OpenGLTextureMagFilterConversions::GetOpenGLMagFilter(GetMagFilter()));*/

		/*
		* Validate and generate mipmaps
		*/
		/*if(HasMipmaps())
			glGenerateMipmap(GL_TEXTURE_2D);*/

		/*
		* Unbind texture
		*/
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenGLTexture2D::InitializeCore()
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
			OpenGLTextureInternalFormatConversions::GetOpenGLTextureInternalFormat(GetTextureInternalFormat()),
			GetWidth(), GetHeight(),
			0,
			OpenGLTextureFormatConversions::GetOpenGLTextureFormat(GetTextureFormat()),
			OpenGLTextureDataTypeConversions::GetOpenGLTextureDataType(GetTextureDataType()),
			nullptr);

		/*
		* Set texture parameters
		*/
		/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, OpenGLTextureWrapModeConversions::GetOpenGLWrapMode(GetWrapModeS()));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, OpenGLTextureWrapModeConversions::GetOpenGLWrapMode(GetWrapModeT()));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, OpenGLTextureMinFilterConversions::GetOpenGLMinFilter(GetMinFilter()));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, OpenGLTextureMagFilterConversions::GetOpenGLMagFilter(GetMagFilter()));*/

		/*
		* Unbind texture
		*/
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenGLTexture2D::FreeDeviceObjectCore()
	{
		glDeleteTextures(1, &m_TextureID);
	}

}