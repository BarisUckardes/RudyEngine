#include "WindowLayout.h"
#include <Bite/Editor/Session/EditorSession.h>
#include <Bite/GUI/Painter/GUIPainter.h>
namespace Bite
{
    GENERATE_REFLECTABLE_TYPE(WindowLayout);
    Rudy::String WindowLayout::GetWindowName() const
    {
        return "Unnamed Window";
    }
    EditorSession* WindowLayout::GetOwnerSession() const
    {
        return m_OwnerSession;
    }
    GUIPainter* WindowLayout::GetPainter() const
    {
        return m_OwnerSession->GetSessionPainter();
    }
    GUIPainterEventLedger* WindowLayout::GetEventLedger() const
    {
        return m_OwnerSession->GetSessionPainter()->GetEventLedger();
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