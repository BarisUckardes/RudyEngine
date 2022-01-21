#pragma once
#include <Rudy/Graphics/Texture/Texture.h>
#include <Rudy/Memory/Memory.h>
#include <Rudy/Graphics/Texture/Texture2DDiskLoadResult.h>
namespace Rudy
{
	class String;
	class AssetPackage;
	class Asset;
	/// <summary>
	/// Graphics api agnostic texture2D class
	/// </summary>
	class RUDY_API Texture2D : public Texture
	{
	public:
		/// <summary>
		/// Loads the texture directly from the disk
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		static Asset* LoadFromDisk(const String& path,bool bCreateMipmaps, AssetPackage* ownerPackage, GraphicsDevice* device);
		static Texture2DDiskLoadResult LoadToMemoryFromDisk(const String& path);

		/// <summary>
		/// Returns the width of the texture
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetWidth() const;

		/// <summary>
		/// Returns the height of the texture
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetHeight() const;

		/// <summary>
		/// Returns the wrap mode S for this texture
		/// </summary>
		/// <returns></returns>
		FORCEINLINE TextureWrapMode GetWrapModeS() const;

		/// <summary>
		/// Returns the wrap mode T for this texture;
		/// </summary>
		/// <returns></returns>
		FORCEINLINE TextureWrapMode GetWrapModeT() const;

		/// <summary>
		/// Updates the texture with data given
		/// </summary>
		/// <param name="data"></param>
		/// <param name="size"></param>
		virtual void SetTextureData(Byte* data, unsigned int size) = 0;

		/// <summary>
		/// Graphics api implementations of a texture2D
		/// </summary>
		/// <param name="width"></param>
		/// <param name="height"></param>
		/// <param name="format"></param>
		/// <param name="internalFormat"></param>
		/// <param name="dataType"></param>
		/// <param name="minFilter"></param>
		/// <param name="magFilter"></param>
		/// <param name="wrapModeS"></param>
		/// <param name="wrapModeT"></param>
		/// <param name="createMipmaps"></param>
		void Initialize(unsigned int width, unsigned int height,
			TextureFormat format, TextureInternalFormat internalFormat, TextureDataType dataType,
			TextureMinFilter minFilter, TextureMagFilter magFilter,
			TextureWrapMode wrapModeS, TextureWrapMode wrapModeT,
			bool bCreateMipmaps);
	protected:
		Texture2D() = default;
		~Texture2D() = default;
		/// <summary>
		/// Sets the width
		/// </summary>
		/// <param name="width"></param>
		void SetWidth(unsigned int width);

		/// <summary>
		/// Sets the height
		/// </summary>
		/// <param name="height"></param>
		void SetHeight(unsigned int height);

		/// <summary>
		/// Sets the wrap mode S
		/// </summary>
		/// <param name="mode"></param>
		void SetWrapModeS(TextureWrapMode mode);

		/// <summary>
		/// Sets the wrap mode T
		/// </summary>
		/// <param name="mode"></param>
		void SetWrapModeT(TextureWrapMode mode);

		/// <summary>
		/// Graphics api implementation of the initialization
		/// </summary>
		/// <param name="width"></param>
		/// <param name="height"></param>
		/// <param name="format"></param>
		/// <param name="internalFormat"></param>
		/// <param name="dataType"></param>
		/// <param name="minFilter"></param>
		/// <param name="magFilter"></param>
		/// <param name="wrapModeS"></param>
		/// <param name="wrapModeT"></param>
		/// <param name="createMipmaps"></param>
		virtual void InitializeCore() = 0;
	private:
		TextureWrapMode m_WrapModeS;
		TextureWrapMode m_WrapModeT;
		unsigned int m_Width;
		unsigned int m_Height;
	};
}