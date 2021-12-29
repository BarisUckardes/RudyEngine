#pragma once
#include <Rudy/Graphics/Shader/ShaderStage.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL shaader stage convertor
	/// </summary>
	class RUDY_API OpenGLShaderStageConversions
	{
	public:
		OpenGLShaderStageConversions() = delete;
		~OpenGLShaderStageConversions() = delete;

		/// <summary>
		/// Returns the opengl representation of the shader stage
		/// </summary>
		/// <param name="stage"></param>
		/// <returns></returns>
		static unsigned int GetOpenGLShaderStage(ShaderStage stage);
	};


}