#pragma once
#include <Rudy/Memory/String.h>
#include <Rudy/Graphics/Texture/TextureFormat.h>
#include <Rudy/Graphics/Texture/TextureInternalFormat.h>
#include <Rudy/Graphics/Texture/TextureDataType.h>

namespace Rudy
{
    /// <summary>
    /// Data volume for framebuffer attachment creation
    /// </summary>
    struct RUDY_API FramebufferAttachmentCreateParameters
    {
        FramebufferAttachmentCreateParameters(const String& name,TextureFormat format,TextureInternalFormat internalFormat,TextureDataType dataType);
        ~FramebufferAttachmentCreateParameters() = default;

        /// <summary>
        /// The name of this framebuffer attachment
        /// </summary>
        String Name;

        /// <summary>
        /// The format of this framebuffer attachment
        /// </summary>
        TextureFormat Format;

        /// <summary>
        /// The internal format of this framebuffer attachment
        /// </summary>
        TextureInternalFormat InternalFormat;

        /// <summary>
        /// The data type of this framebuffer attachment
        /// </summary>
        TextureDataType DataType;
    };
}
