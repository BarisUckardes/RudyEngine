#include "KeyboardKeyDownEvent.h"

namespace Rudy
{
    KeyboardKeyDownEvent::KeyboardKeyDownEvent(unsigned int downKey) : KeyboardKeyEvent(downKey)
    {
    }
    EventType KeyboardKeyDownEvent::GetEventType() const
    {
        return EventType::KeyboardKeyDown;
    }

    String KeyboardKeyDownEvent::GetAsString() const
    {
        return "Key down event";
    }

}