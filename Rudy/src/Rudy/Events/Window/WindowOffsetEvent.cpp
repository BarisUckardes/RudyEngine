#include "WindowOffsetEvent.h"


namespace Rudy
{
    WindowOffsetEvent::WindowOffsetEvent(const Vector2i& offset)
    {
        m_Offset = offset;
    }
    Vector2i WindowOffsetEvent::GetOffset() const
    {
        return m_Offset;
    }
    EventType WindowOffsetEvent::GetEventType() const
    {
        return EventType::WindowOffsetChanged;
    }
    String WindowOffsetEvent::GetAsString() const
    {
        return "Window offset changed";
    }
}