#include "Texture2D.h"
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Asset/Asset.h>
#include <Rudy/Asset/AssetPackage.h>
#include <STBI/stb_image.h>
#include <GLAD/glad.h>
namespace Rudy
{
	int Texture2D::GetOpenGLTexture(const String& path)
	{

		/*
		* Set stbi configuration
		*/
		//stbi_set_flip_vertically_on_load(1);

		/*
		* Load stbi data
		*/
		Byte* data = nullptr;
		int width, height, channels;
		data = stbi_load(*path, &width, &height, &channels, 0);

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glBindTexture(GL_TEXTURE_2D, 0);
		return texture;
	}
	Asset* Texture2D::LoadFromDisk(const String& path, bool bCreateMipmaps, AssetPackage* ownerPackage, GraphicsDevice* device)
	{
		/*
		* Create virtual asset and register it
		*/
		Asset* asset = ownerPackage->RegisterVirtualAsset(path, true);
		return asset;
	}
	Texture2DDiskLoadResult Texture2D::LoadToMemoryFromDisk(const String& path)
	{
		/*
		* Validate file
		*/
		if (!PlatformFile::IsFileExists(path))
			return Texture2DDiskLoadResult();

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
		//stbi_set_flip_vertically_on_load(1);

		/*
		* Load stbi data
		*/
		Byte* data = nullptr;
		data = stbi_load(*path, &width, &height, &channels, 0);

		/*
		* Validate data dimensions
		*/
		if (width <= 0 || height <= 0 || !data)
		{
			printf("\nStbi image data is corrupted\n");
			return Texture2DDiskLoadResult();
		}

		/*
		* Create result s
		*/
		Texture2DDiskLoadResult loadResult;
		loadResult.DataBlock = ByteBlock(data,width*height*channels);
		loadResult.NativaDataBlock = data;
		loadResult.ChannelCount = channels;
		loadResult.Width = width;
		loadResult.Height = height;

		/*
		* Free stbi data
		*/
		//stbi_image_free(data);

		return loadResult;
	}
	
	void Texture2D::Initialize(unsigned int width, unsigned int height, TextureFormat format, TextureInternalFormat internalFormat, TextureDataType dataType, TextureMinFilter minFilter, TextureMagFilter magFilter, TextureWrapMode wrapModeS, TextureWrapMode wrapModeT, bool bCreateMipmaps)
	{
		/*
		* Set properties
		*/
		SetWidth(width);
		SetHeight(height);
		SetTextureFormat(format);
		SetTextureInternalFormat(internalFormat);
		SetTextureDataType(dataType);
		SetMinFilter(minFilter);
		SetMagFilter(magFilter);
		SetWrapModeS(wrapModeS);
		SetWrapModeT(wrapModeT);
		SetMipmapState(bCreateMipmaps);

		/*
		* Call graphics api implementation
		*/
		InitializeCore();
	}
	unsigned int Texture2D::GetWidth() const
	{
		return m_Width;
	}
	unsigned int Texture2D::GetHeight() const
	{
		return m_Height;
	}
	TextureWrapMode Texture2D::GetWrapModeS() const
	{
		return m_WrapModeS;
	}
	TextureWrapMode Texture2D::GetWrapModeT() const
	{
		return m_WrapModeT;
	}
	void Texture2D::SetWidth(unsigned int width)
	{
		m_Width = width;
	}
	void Texture2D::SetHeight(unsigned int height)
	{
		m_Height = height;
	}
	void Texture2D::SetWrapModeS(TextureWrapMode mode)
	{
		m_WrapModeS = mode;
	}
	void Texture2D::SetWrapModeT(TextureWrapMode mode)
	{
		m_WrapModeT = mode;
	}
}