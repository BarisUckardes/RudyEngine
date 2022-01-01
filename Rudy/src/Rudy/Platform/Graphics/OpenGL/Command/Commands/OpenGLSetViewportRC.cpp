#include "OpenGLSetViewportRC.h"
#include <GLAD/glad.h>

namespace Rudy
{
	OpenGLSetViewportRC::OpenGLSetViewportRC(const Vector2i& offset,const Vector2i& size)
	{
		m_Offset = offset;
		m_Size = size;
	}

	void OpenGLSetViewportRC::Execute()
	{
		glViewport(m_Offset.X, m_Offset.Y, m_Size.X, m_Size.Y);
	}
}