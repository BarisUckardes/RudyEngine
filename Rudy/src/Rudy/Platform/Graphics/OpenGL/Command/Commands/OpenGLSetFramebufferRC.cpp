#include "OpenGLSetFramebufferRC.h"
#include <GLAD/glad.h>
namespace Rudy
{
	OpenGLSetFramebufferRC::OpenGLSetFramebufferRC(unsigned int framebufferID)
	{
		m_FramebufferID = framebufferID;
	}

	void OpenGLSetFramebufferRC::Execute()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_FramebufferID);
	}
}