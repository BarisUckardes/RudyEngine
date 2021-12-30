#pragma once
#include <Rudy/Graphics/Framebuffer/Framebuffer.h>

namespace Rudy
{
	class RUDY_API OpenGLFramebuffer2D : Framebuffer
	{
	public:
		OpenGLFramebuffer2D() = default;
		~OpenGLFramebuffer2D() = default;

		virtual void* GetNativeHandle() const override;
	protected:
		virtual void CreateCore(unsigned int width, unsigned int height,const Array<FramebufferAttachmentCreateParameters>& createParameters, Array<FramebufferAttachment*>& attachments, Texture2D* depthTexture, bool createDepthTexture) override;
	private:
		unsigned int m_FramebufferID;
	};


}