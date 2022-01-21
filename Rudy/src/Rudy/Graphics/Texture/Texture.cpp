#include "Texture.h"

namespace Rudy
{
	Texture::~Texture()
	{

	}
	TextureFormat Texture::GetTextureFormat() const
	{
		return m_Format;
	}

	TextureInternalFormat Texture::GetTextureInternalFormat() const
	{
		return m_InternalFormat;
	}

	TextureDataType Texture::GetTextureDataType() const
	{
		return m_DataType;
	}

	TextureMinFilter Texture::GetMinFilter() const
	{
		return m_MinFilter;
	}

	TextureMagFilter Texture::GetMagFilter() const
	{
		return m_MagFilter;
	}

	bool Texture::HasMipmaps() const
	{
		return m_HasMipmaps;
	}

	void Texture::SetTextureFormat(TextureFormat format)
	{
		m_Format = format;
	}
	void Texture::SetTextureInternalFormat(TextureInternalFormat internalFormat)
	{
		m_InternalFormat = internalFormat;
	}
	void Texture::SetTextureDataType(TextureDataType dataType)
	{
		m_DataType = dataType;
	}
	void Texture::SetMinFilter(TextureMinFilter filter)
	{
		m_MinFilter = filter;
	}
	void Texture::SetMagFilter(TextureMagFilter filter)
	{
		m_MagFilter = filter;
	}
	void Texture::SetMipmapState(bool state)
	{
		m_HasMipmaps = state;
	}
}