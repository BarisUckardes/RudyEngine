#pragma once
#include <Rudy/Graphics/Shader/ShaderProgram.h>

namespace Rudy
{
	/// <summary>
	/// OpenGl implementation of a shader program
	/// </summary>
	class RUDY_API OpenGLShaderProgram : public ShaderProgram
	{
	public:
		OpenGLShaderProgram() = default;
		~OpenGLShaderProgram() = default;


		virtual void* GetNativeHandle() const override;
		virtual void LinkProgramCore(Array<Shader*>& shaders, bool& linkState, String& errorMessage) override;
	private:
		unsigned int m_ProgramID;
	};
}