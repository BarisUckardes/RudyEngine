#pragma once
#include <Rudy/Graphics/Texture/TextureMagFilter.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL texture mag filter convertor
	/// </summary>
	class RUDY_API OpenGLTextureMagFilterConversions
	{
	public:
		OpenGLTextureMagFilterConversions() = delete;
		~OpenGLTextureMagFilterConversions() = delete;


		/// <summary>
		/// Returns the OpenGL representation of the texture mag filter
		/// </summary>
		/// <param name="filter"></param>
		/// <returns></returns>
		static unsigned int GetOpenGLMagFilter(TextureMagFilter filter);
	};

}
