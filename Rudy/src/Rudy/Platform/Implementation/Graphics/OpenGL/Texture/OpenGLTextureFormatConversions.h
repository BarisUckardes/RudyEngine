#pragma once
#include <Rudy/Graphics/Texture/TextureFormat.h>

namespace Rudy
{
	/// <summary>
	/// Convertor for opengl texture format
	/// </summary>
	class RUDY_API OpenGLTextureFormatConversions
	{
	public:

		/// <summary>
		/// Returns opengl format via graphics api agnostic texture format
		/// </summary>
		/// <param name="format"></param>
		/// <returns></returns>
		static unsigned int GetOpenGLTextureFormat(TextureFormat format);
		OpenGLTextureFormatConversions() = delete;
		~OpenGLTextureFormatConversions() = delete;

	};
}