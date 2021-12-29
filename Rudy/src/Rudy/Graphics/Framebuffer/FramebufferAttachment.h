#pragma once
#include <Rudy/Graphics/Texture/Texture2D.h>

namespace Rudy
{
    /// <summary>
    /// Data volume for single framebuffer texture attachment
    /// </summary>
    class RUDY_API FramebufferAttachment
    {
    public:
        FramebufferAttachment(Texture2D* texture,
            TextureFormat format, TextureInternalFormat internalFormat,
            TextureDataType dataType,
            unsigned int width, unsigned int height);
        ~FramebufferAttachment();

        /// <summary>
        /// Returns the texture of this framebuffer attachment
        /// </summary>
        /// <returns></returns>
        FORCEINLINE Texture2D* GetTexture() const;

        /// <summary>
        /// Returns the texture format of this framebuffer attachment
        /// </summary>
        /// <returns></returns>
        FORCEINLINE TextureFormat GetFormat() const;

        /// <summary>
        /// Returns texture internal format of this framebuffer attachment
        /// </summary>
        /// <returns></returns>
        FORCEINLINE TextureInternalFormat GetInternalFormat() const;

        /// <summary>
        /// Returns the texture data type of this framebuffer attachment
        /// </summary>
        /// <returns></returns>
        FORCEINLINE TextureDataType GetDataType() const;

        /// <summary>
        /// Returns the width of this framebuffer attachment
        /// </summary>
        /// <returns></returns>
        FORCEINLINE unsigned int GetWidth() const;

        /// <summary>
        /// Returns the height of this framebuffer attachment
        /// </summary>
        /// <returns></returns>
        FORCEINLINE unsigned int GetHeight() const;
    private:
        Texture2D* m_Texture;
        TextureFormat m_Format;
        TextureInternalFormat m_InternalFormat;
        TextureDataType m_DataType;
        unsigned int m_Width;
        unsigned int m_Height;
    };
}