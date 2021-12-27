#include "WindowResizedEvent.h"
#include <stdio.h>
#include <iostream>
namespace Rudy
{
    WindowResizedEvent::WindowResizedEvent(const Vector2i& size)
    {
        m_Size = size;
    }
    Vector2i WindowResizedEvent::GetSize() const
    {
        return m_Size;
    }
    EventType WindowResizedEvent::GetEventType() const
    {
        return EventType::WindowResized;
    }
    String WindowResizedEvent::GetAsString() const
    {
        return "Window resized event";
    }
}