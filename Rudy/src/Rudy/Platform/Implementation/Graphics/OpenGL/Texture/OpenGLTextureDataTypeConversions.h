#pragma once
#include <Rudy/Graphics/Texture/TextureDataType.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL texture data convertor
	/// </summary>
	class RUDY_API OpenGLTextureDataTypeConversions
	{
	public:
		OpenGLTextureDataTypeConversions() = delete;
		~OpenGLTextureDataTypeConversions() = delete;

		/// <summary>
		/// Returns the OpenGL representation of the texture data type
		/// </summary>
		/// <param name="dataType"></param>
		/// <returns></returns>
		static unsigned int GetOpenGLTextureDataType(TextureDataType dataType);
	};


}