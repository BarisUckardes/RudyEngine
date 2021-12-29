#pragma once
#include <Rudy/Graphics/Texture/Texture.h>

namespace Rudy
{
	/// <summary>
	/// Graphics api agnostic texture2D class
	/// </summary>
	class RUDY_API Texture2D : public Texture
	{
	public:
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

		virtual ~Texture2D() = default;

		/// <summary>
		/// Updates the texture with data given
		/// </summary>
		/// <param name="data"></param>
		/// <param name="size"></param>
		virtual void SetTextureData(unsigned char* data, unsigned int size) = 0;
	protected:
		Texture2D(GraphicsDevice* device);

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
	private:
		TextureWrapMode m_WrapModeS;
		TextureWrapMode m_WrapModeT;
		unsigned int m_Width;
		unsigned int m_Height;
	};
}