#include "OpenGLShader.h"
#include <GLAD/glad.h>
#include <Rudy/Platform/Graphics/OpenGL/Shader/OpenGLShaderStageConversions.h>
namespace Rudy
{
	OpenGLShader::OpenGLShader(GraphicsDevice* device) : Shader(device)
	{

	}
	OpenGLShader::~OpenGLShader()
	{

	}
	void* OpenGLShader::GetNativeHandle() const
	{
		return (void*)&m_ShaderID;
	}

	void OpenGLShader::CompileCore(const String& source, bool& isCompiled, String& errorMessage)
	{
		/*
		* Delete formet openGLShader
		*/
		glDeleteShader(m_ShaderID);

		/*
		* Create new shader
		*/
		m_ShaderID = glCreateShader(OpenGLShaderStageConversions::GetOpenGLShaderStage(GetStage()));

		/*
		* Set shader source
		*/
		const GLchar* sourcePtr = source.GetSource();
		glShaderSource(m_ShaderID, 1,&sourcePtr, 0);

		/*
		* Compile shader
		*/
		glCompileShader(m_ShaderID);

		/*
		* Validate compilation result and generate error messsage
		*/
		GLint state = 0;
		glGetShaderiv(m_ShaderID, GL_COMPILE_STATUS, &state);
		if (state == GL_FALSE)
		{
			GLint maxLength = 255;
			glGetShaderiv(m_ShaderID, GL_INFO_LOG_LENGTH, &maxLength);

			char* errorLog = new char[maxLength];
			glGetShaderInfoLog(m_ShaderID, maxLength, &maxLength, errorLog);
			glDeleteShader(m_ShaderID);

			/*
			* Set error message
			*/
			errorMessage = errorLog;
			isCompiled = false;
		}
		else
		{
			errorMessage = "";
			isCompiled = true;
		}

	}

}