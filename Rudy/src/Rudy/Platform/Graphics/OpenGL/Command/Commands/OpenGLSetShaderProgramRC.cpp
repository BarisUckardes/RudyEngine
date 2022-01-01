#include "OpenGLSetShaderProgramRC.h"
#include <GLAD/glad.h>
namespace Rudy
{
	OpenGLSetShaderProgramRC::OpenGLSetShaderProgramRC(unsigned int programID)
	{
		m_ProgramID = programID;
	}
	void OpenGLSetShaderProgramRC::Execute()
	{
		glUseProgram(m_ProgramID);
	}
}