#pragma once
#include <Rudy/Graphics/Texture/TextureMinFilter.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL texture min filter convertor
	/// </summary>
	class RUDY_API OpenGLTextureMinFilterConversions
	{
	public:
		OpenGLTextureMinFilterConversions() = delete;
		~OpenGLTextureMinFilterConversions() = delete;

		/// <summary>
		/// Returns the opengl representations of the texture min filter
		/// </summary>
		/// <param name="filter"></param>
		/// <returns></returns>
		static unsigned int GetOpenGLMinFilter(TextureMinFilter filter);
	};


}