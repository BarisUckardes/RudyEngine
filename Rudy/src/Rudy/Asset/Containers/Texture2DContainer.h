#pragma once
#include <Rudy/Graphics/Texture/TextureFormat.h>
#include <Rudy/Graphics/Texture/TextureInternalFormat.h>
#include <Rudy/Graphics/Texture/TextureDataType.h>
#include <Rudy/Graphics/Texture/TextureMinFilter.h>
#include <Rudy/Graphics/Texture/TextureMagFilter.h>
#include <Rudy/Graphics/Texture/TextureWrapMode.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{
	/// <summary>
	/// Data volume for texture2D object
	/// </summary>
	struct RUDY_API Texture2DContainer
	{
		/// <summary>
		/// The format of the texture
		/// </summary>
		TextureFormat Format;

		/// <summary>
		/// The internal format of the texture
		/// </summary>
		TextureInternalFormat InternalFormat;

		/// <summary>
		/// The data type of the single pixel of the texture
		/// </summary>
		TextureDataType DataType;

		/// <summary>
		/// Minification filter of the texture
		/// </summary>
		TextureMinFilter MinFilter;

		/// <summary>
		/// Magnification filter of the texture
		/// </summary>
		TextureMagFilter MagFilter;

		/// <summary>
		/// Horizontal wrapping mode of the texture
		/// </summary>
		TextureWrapMode WrapModeS;

		/// <summary>
		/// Vertical wrapping mode of the texture
		/// </summary>
		TextureWrapMode WrapModeT;

		/// <summary>
		/// Width of the texture
		/// </summary>
		unsigned int Width;

		/// <summary>
		/// Height of the texture
		/// </summary>
		unsigned int Height;

		/// <summary>
		/// Generate mipmap flags
		/// </summary>
		bool GenerateMipmaps;

		/// <summary>
		/// Uncompressed raw texture data
		/// </summary>
		Array<unsigned char> Data;
	};
}