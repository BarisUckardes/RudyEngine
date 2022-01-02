#include "OpenGLFramebuffer2D.h"
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <GlAD/glad.h>
namespace Rudy
{
	void* OpenGLFramebuffer2D::GetNativeHandle() const
	{
		return (void*)&m_FramebufferID;
	}

	void OpenGLFramebuffer2D::CreateCore(unsigned int width, unsigned int height,const Array<FramebufferAttachmentCreateParameters>& createParameters, Array<FramebufferAttachment*>& attachments, Texture2D* depthTexture, bool createDepthTexture)
	{
		/*
		* Create framebuffer
		*/
		glGenFramebuffers(1, &m_FramebufferID);

		/*
		* Bind framebuffer
		*/
		glBindFramebuffer(GL_FRAMEBUFFER, m_FramebufferID);

		/*
		* Create textures
		*/
		unsigned int colorAttachmentSlot = GL_COLOR_ATTACHMENT0;
		Array<unsigned int> attachmentSlotList;
		for (int i = 0; i < createParameters.GetCursor(); i++)
		{
			/*
			* Get create parameters
			*/
			const FramebufferAttachmentCreateParameters& createParameter = createParameters[i];

			/*
			* Create texture2D
			*/
			Texture2D* texture = GetOwnerGraphicsDevice()->CreateTexture2D();

			/*
			* Initialize texture
			*/
			texture->Initialize(width, height,
				createParameter.Format, createParameter.InternalFormat, createParameter.DataType,
				TextureMinFilter::Nearest, TextureMagFilter::Nearest,
				TextureWrapMode::Repeat, TextureWrapMode::Repeat, false);

			/*
			* Get texture OpenGL id
			*/
			unsigned int textureID = *(unsigned int*)texture->GetNativeHandle();

			/*
			* Set color attachment
			*/
			glFramebufferTexture2D(GL_FRAMEBUFFER, colorAttachmentSlot, GL_TEXTURE_2D, textureID, 0);

			/*
			* Register attachment slot
			*/
			attachmentSlotList.Add(colorAttachmentSlot);

			/*
			* Increment attachment slot
			*/
			colorAttachmentSlot++;

			/*
			* Create new framebuffer attachment
			*/
			attachments.Add(new FramebufferAttachment(texture,
				createParameter.Format, createParameter.InternalFormat, createParameter.DataType,
				width, height));
		}

		/*
		* Create depth texture if requests
		*/
		if (createDepthTexture)
		{
			/*
			* Create texture
			*/
			Texture2D* depthTexture = GetOwnerGraphicsDevice()->CreateTexture2D();

			/*
			* Initialize depth texture
			*/
			depthTexture->Initialize(width, height,
				TextureFormat::DepthComponent, TextureInternalFormat::DepthComponent32f, TextureDataType::Float,
				TextureMinFilter::Nearest, TextureMagFilter::Nearest,
				TextureWrapMode::Repeat, TextureWrapMode::Repeat, false);

			/*
			* Get depth texture opengl ID
			*/
			unsigned int textureID = *(unsigned int*)depthTexture->GetNativeHandle();

			/*
			* Set depth attachment
			*/
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, textureID,0);

			/*
			* Set depth texture
			*/
			depthTexture = depthTexture;
		}

		/*
		* Draw buffers
		*/
		glDrawBuffers(createParameters.GetCursor(), attachmentSlotList.GetData());

		/*
		* Unbind framebuffer
		*/
		glBindFramebuffer(GL_TEXTURE_2D, 0);

	}

	void OpenGLFramebuffer2D::FreeDeviceObjectCore()
	{
		glDeleteFramebuffers(1, &m_FramebufferID);
	}

}