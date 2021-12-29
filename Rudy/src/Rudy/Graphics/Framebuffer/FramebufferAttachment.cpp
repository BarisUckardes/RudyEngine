#include "FramebufferAttachment.h"

namespace Rudy
{
    FramebufferAttachment::FramebufferAttachment(Texture2D* texture,
        TextureFormat format, TextureInternalFormat internalFormat,
        TextureDataType dataType,
        unsigned int width, unsigned int height)
    {
        m_Texture = texture;
        m_Format = format;
        m_InternalFormat = internalFormat;
        m_DataType = dataType;
        m_Width = width;
        m_Height = height;
    }
    FramebufferAttachment::~FramebufferAttachment()
    {
        delete m_Texture;
        m_Texture = nullptr;
    }
    Texture2D* FramebufferAttachment::GetTexture() const
    {
        return m_Texture;
    }
    TextureFormat FramebufferAttachment::GetFormat() const
    {
        return m_Format;
    }
    TextureInternalFormat FramebufferAttachment::GetInternalFormat() const
    {
        return m_InternalFormat;
    }
    TextureDataType FramebufferAttachment::GetDataType() const
    {
        return m_DataType;
    }
    unsigned int FramebufferAttachment::GetWidth() const
    {
        return m_Width;
    }
    unsigned int FramebufferAttachment::GetHeight() const
    {
        return m_Height;
    }
}