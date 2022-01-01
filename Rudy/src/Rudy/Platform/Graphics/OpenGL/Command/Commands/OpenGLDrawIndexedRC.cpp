#include "OpenGLDrawIndexedRC.h"
#include <GLAD/glad.h>
namespace Rudy
{
	OpenGLDrawIndexedRC::OpenGLDrawIndexedRC(unsigned int count)
	{
		m_Count = count;
	}

	void OpenGLDrawIndexedRC::Execute()
	{
		glDrawElements(GL_TRIANGLES, m_Count, GL_UNSIGNED_INT, nullptr);
	}
}