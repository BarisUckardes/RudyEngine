#include "KeyboardKeyReleasedEvent.h"

namespace Rudy
{
    KeyboardKeyReleasedEvent::KeyboardKeyReleasedEvent(unsigned int releasedKey) : KeyboardKeyEvent(releasedKey)
    {

    }
    EventType KeyboardKeyReleasedEvent::GetEventType() const
    {
        return EventType::KeyboardKeyUp;
    }

    String KeyboardKeyReleasedEvent::GetAsString() const
    {
        return "Key released";
    }

}