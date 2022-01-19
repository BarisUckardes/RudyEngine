#pragma once
#include <Rudy/Graphics/Texture/TextureInternalFormat.h>

namespace Rudy
{
	/// <summary>
	/// Opengl texture internal format convertor
	/// </summary>
	class RUDY_API OpenGLTextureInternalFormatConversions
	{
	public:
		OpenGLTextureInternalFormatConversions() = delete;
		~OpenGLTextureInternalFormatConversions() = delete;

		/// <summary>
		/// Returns the opengl representation of the texture internal format
		/// </summary>
		/// <returns></returns>
		static unsigned int GetOpenGLTextureInternalFormat(TextureInternalFormat internalFormat);
	};


}