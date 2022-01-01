#include "OpenGLClearColorRC.h"
#include <GLAD/glad.h>

namespace Rudy
{
    OpenGLClearColorRC::OpenGLClearColorRC(const ColorRgba& color)
    {
        m_Color = color;
    }
    void OpenGLClearColorRC::Execute()
    {
        glClearColor(m_Color.R,m_Color.G,m_Color.B,m_Color.A);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}