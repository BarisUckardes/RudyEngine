#include "Texture2D.h"
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <STBI/stb_image.h>

namespace Rudy
{
	Texture2D* Texture2D::LoadFromDisk(GraphicsDevice* device,const String& path,bool bCreateMipmaps)
	{
		/*
		* Validate file
		*/
		if (!PlatformFile::IsFileExists(path))
			return nullptr;

		/*
		* Load texture data from the disk
		*/
		int width, height, channels;
		TextureFormat format;
		TextureInternalFormat internalFormat;
		TextureDataType dataType;

		/*
		* Set stbi configuration
		*/
		stbi_set_flip_vertically_on_load(1);

		/*
		* Load stbi data
		*/
		stbi_uc* data = nullptr;
		{
			data = stbi_load(*path, &width, &height, &channels, 0);
		}

		/*
		* Validate data dimensions
		*/
		if (width <= 0 || height <= 0)
		{
			return nullptr;
		}

		/*
		* Minimal format catch
		*/
		if (channels == 3) // RGB
		{
			format = TextureFormat::Rgb;
			internalFormat = TextureInternalFormat::Rgb32f;
		}
		else if (channels == 4) // RGBA
		{
			format = TextureFormat::Rgba;
			internalFormat = TextureInternalFormat::Rgba32f;
		}
		dataType = TextureDataType::UnsignedByte;

		/*
		* Create texture
		*/
		Texture2D* texture = device->CreateTexture2D();
		texture->Initialize(width, height,
			format, internalFormat,
			dataType,
			TextureMinFilter::Linear, TextureMagFilter::Linear,
			TextureWrapMode::Repeat, TextureWrapMode::Repeat,bCreateMipmaps);

		/*
		* Set texture data
		*/
		texture->SetTextureData(data, width * height * channels);

		return texture;
	}
	unsigned int Texture2D::GetWidth() const
	{
		return m_Width;
	}
	unsigned int Texture2D::GetHeight() const
	{
		return m_Height;
	}
	void Texture2D::SetWidth(unsigned int width)
	{
		m_Width = width;
	}
	void Texture2D::SetHeight(unsigned int height)
	{
		m_Height = height;
	}
}