#include "OpenGLClearDepthRC.h"
#include <GLAD/glad.h>
#include <stdio.h>
namespace Rudy
{
	OpenGLClearDepthRC::OpenGLClearDepthRC(float value)
	{
		m_DetphValue = value;
	}

	void OpenGLClearDepthRC::Execute()
	{
		glClearDepth(m_DetphValue);
		glClear(GL_DEPTH_BUFFER_BIT);
	}
}