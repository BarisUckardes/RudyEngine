#pragma once
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
#include <Rudy/Graphics/Texture/TextureFormat.h>
#include <Rudy/Graphics/Texture/TextureInternalFormat.h>
#include <Rudy/Graphics/Texture/TextureDataType.h>
#include <Rudy/Graphics/Texture/TextureMagFilter.h>
#include <Rudy/Graphics/Texture/TextureMinFilter.h>
#include <Rudy/Graphics/Texture/TextureWrapMode.h>
#include <Rudy/Object/RudyObject.h>
namespace Rudy
{
	/// <summary>
	/// Platform diagnostic texture class
	/// </summary>
	class RUDY_API Texture : public GraphicsDeviceObject
	{
	public:
		Texture() = default;
		virtual ~Texture() = 0;
		/// <summary>
		/// Returns the format of this texture
		/// </summary>
		/// <returns></returns>
		FORCEINLINE TextureFormat GetTextureFormat() const;

		/// <summary>
		/// Returs the internal format of this texture
		/// </summary>
		/// <returns></returns>
		FORCEINLINE TextureInternalFormat GetTextureInternalFormat() const;

		/// <summary>
		/// Returns the data type of this texture;
		/// </summary>
		/// <returns></returns>
		FORCEINLINE TextureDataType GetTextureDataType() const;

		/// <summary>
		/// Returns the min filter of this texture
		/// </summary>
		/// <returns></returns>
		FORCEINLINE TextureMinFilter GetMinFilter() const;

		/// <summary>
		/// Returns the mag filter of this texture
		/// </summary>
		/// <returns></returns>
		FORCEINLINE TextureMagFilter GetMagFilter() const;

		/// <summary>
		/// Returns whether this texture has mipmaps or not
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool HasMipmaps() const;

		/// <summary>
		/// Sets the texture format of this texture
		/// </summary>
		/// <param name="format"></param>
		void SetTextureFormat(TextureFormat format);

		/// <summary>
		/// Sets the texture internal format of this texture
		/// </summary>
		/// <param name="internalFormat"></param>
		void SetTextureInternalFormat(TextureInternalFormat internalFormat);

		/// <summary>
		/// Sets the texture data type of this texture
		/// </summary>
		/// <param name="dataType"></param>
		void SetTextureDataType(TextureDataType dataType);

		/// <summary>
		/// Sets min filter of this texture
		/// </summary>
		/// <param name="filter"></param>
		void SetMinFilter(TextureMinFilter filter);

		/// <summary>
		/// Sets mag filter of this texture
		/// </summary>
		/// <param name="filter"></param>
		void SetMagFilter(TextureMagFilter filter);

		/// <summary>
		/// Sets mipmap state of this texture
		/// </summary>
		/// <param name="state"></param>
		void SetMipmapState(bool state);
	private:
		
		TextureFormat m_Format;
		TextureInternalFormat m_InternalFormat;
		TextureDataType m_DataType;
		TextureMinFilter m_MinFilter;
		TextureMagFilter m_MagFilter;
		bool m_HasMipmaps;

	};


}