#include "WindowLayout.h"

namespace Bite
{
    Rudy::String WindowLayout::GetWindowName() const
    {
        return "Unnamed Window";
    }
    EditorSession* WindowLayout::GetOwnerSession() const
    {
        return m_OwnerSession;
    }
    void WindowLayout::SetEditorSession(EditorSession* session)
    {
        m_OwnerSession = session;
    }
    void WindowLayout::SetVisibilityState(bool state)
    {
        m_Visible = state;
    }
    bool WindowLayout::IsVisible() const
    {
        return m_Visible;
    }
}