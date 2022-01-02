#include "Framebuffer.h"

namespace Rudy
{
    Framebuffer::~Framebuffer()
    {

    }
    Array<FramebufferAttachment*> Framebuffer::GetAttachments() const
    {
        return m_Attachments;
    }

    Texture2D* Framebuffer::GetDepthTexture() const
    {
        return m_DepthTexture;
    }

    bool Framebuffer::HasDepthTexture() const
    {
        return m_DepthTexture != nullptr;
    }

    void Framebuffer::Create(unsigned int width, unsigned int height,const Array<FramebufferAttachmentCreateParameters>& createParameters, bool createDetphTexture)
    {
        /*
        * Call implementation
        */
        Array<FramebufferAttachment*> attachments;
        Texture2D* depthTexture = nullptr;
        CreateCore(width,height,createParameters, attachments, depthTexture, createDetphTexture);

        /*
        * Set attachments
        */
        m_Attachments = attachments;
        m_DepthTexture = depthTexture;
        m_HasDepthTexture = createDetphTexture;
    }

    GraphicsDevice* Framebuffer::GetOwnerGraphicsDevice() const
    {
        return GetOwnerGraphicsDevice();
    }

}