#include "OpenGLSetVertexBufferRC.h"
#include <GLAD/glad.h>
namespace Rudy
{
	OpenGLSetVertexBufferRC::OpenGLSetVertexBufferRC(unsigned int vertexArrayID, unsigned int vertexBufferID)
	{
		m_VertexArrayID = vertexArrayID;
		m_VertexBufferID = vertexArrayID;
	}
	void OpenGLSetVertexBufferRC::Execute()
	{
		glBindVertexArray(m_VertexArrayID);
		glBindBuffer(GL_ARRAY_BUFFER,m_VertexArrayID);
	}
}