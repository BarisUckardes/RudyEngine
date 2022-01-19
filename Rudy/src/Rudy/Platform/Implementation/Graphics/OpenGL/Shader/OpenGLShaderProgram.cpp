#include "OpenGLShaderProgram.h"
#include <GLAD/glad.h>
#include <Rudy/Platform/Implementation/Graphics/OpenGL/Shader/OpenGLShaderProgram.h>
namespace Rudy
{
	void* OpenGLShaderProgram::GetNativeHandle() const
	{
		return (void*)&m_ProgramID;
	}
	void OpenGLShaderProgram::LinkProgramCore(Array<Shader*>& shaders, bool& linkState, String& errorMessage)
	{
		/*
		* Delete former shader program
		*/
		glDeleteProgram(m_ProgramID);

		/*
		* Create new program
		*/
		m_ProgramID = glCreateProgram();

		/*
		* Attach shaders
		*/
		for (unsigned int i = 0; i < shaders.GetCursor(); i++)
		{
			/*
			* Get opengl shader
			*/
			OpenGLShaderProgram* shader = (OpenGLShaderProgram*)shaders[i];

			/*
			* Attach shader
			*/
			glAttachShader(m_ProgramID, *(unsigned int*)shader->GetNativeHandle());
		}

		/*
		* Link program
		*/
		glLinkProgram(m_ProgramID);

		/*
		* Validate program and generate error message
		*/
		GLint state = 0;
		glGetProgramiv(m_ProgramID, GL_LINK_STATUS, (int*)&state);
		if (state == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_ProgramID, GL_INFO_LOG_LENGTH, &maxLength);

			char* errorLog = new char[maxLength];
			glGetProgramInfoLog(m_ProgramID, maxLength, &maxLength, errorLog);

			glDeleteProgram(m_ProgramID);

			delete[] errorLog;
			linkState = false;
			errorMessage = errorLog;
		}
		else
		{
			linkState = true;
			errorMessage = "";
		}

	}
	void OpenGLShaderProgram::FreeDeviceObjectCore()
	{
		glDeleteProgram(m_ProgramID);
	}
}