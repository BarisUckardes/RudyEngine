#pragma once
#include <Rudy/Graphics/Texture/TextureWrapMode.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL texture wrap mode convertor
	/// </summary>
	class RUDY_API OpenGLTextureWrapModeConversions
	{
	public:
		OpenGLTextureWrapModeConversions() = delete;
		~OpenGLTextureWrapModeConversions() = delete;


		/// <summary>
		/// Returns the opengl representations of the texture wrap mode
		/// </summary>
		static unsigned int GetOpenGLWrapMode(TextureWrapMode wrapMode);
	};


}