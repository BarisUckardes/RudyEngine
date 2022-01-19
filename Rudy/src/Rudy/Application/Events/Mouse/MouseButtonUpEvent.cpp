#include "MouseButtonUpEvent.h"

namespace Rudy
{
    MouseButtonUpEvent::MouseButtonUpEvent(int button) : MouseButtonEvent(button)
    {
    }
    EventType MouseButtonUpEvent::GetEventType() const
    {
        return EventType::MouseButtonUp;
    }

    String MouseButtonUpEvent::GetAsString() const
    {
        return "Mouse button up event";
    }

}