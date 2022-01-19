#include "OpenGLSetIndexBufferRC.h"
#include <GLAD/glad.h>
namespace Rudy
{
	OpenGLSetIndexBufferRC::OpenGLSetIndexBufferRC(unsigned int indexBufferID)
	{
		m_IndexBufferID = indexBufferID;
	}

	void OpenGLSetIndexBufferRC::Execute()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
	}


}