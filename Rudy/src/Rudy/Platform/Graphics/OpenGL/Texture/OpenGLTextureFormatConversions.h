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
		static unsigned int GetOpenGLTextureFormat(TextureFormat format);
		OpenGLTextureFormatConversions() = delete;
		~OpenGLTextureFormatConversions() = delete;

	};
}