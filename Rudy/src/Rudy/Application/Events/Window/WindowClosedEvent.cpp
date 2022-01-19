#include "WindowClosedEvent.h"

namespace Rudy
{
    EventType WindowClosedEvent::GetEventType() const
    {
        return EventType::WindowClosed;
    }

    String WindowClosedEvent::GetAsString() const
    {
        return "Window closed event";
    }

}