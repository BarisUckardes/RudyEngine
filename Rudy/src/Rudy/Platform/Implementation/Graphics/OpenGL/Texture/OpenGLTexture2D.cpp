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

	void OpenGLTexture2D::SetTextureData(Byte* data, unsigned int size)
	{
		/*
		* Bind texture
		*/
		glBindTexture(GL_TEXTURE_2D, m_TextureID);

		/*
		* Set texture parameters
		*/
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


		/*
		* Set texture data
		*/
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGBA,
			GetWidth(), GetHeight(),
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			data);

	

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
		* Set texture parameters
		*/
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		/*
		* Allocate texture data
		*/
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGBA,
			GetWidth(), GetHeight(),
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			nullptr);

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