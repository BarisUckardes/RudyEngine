#include "KeyboardKeyReleasedEvent.h"

namespace Rudy
{
    KeyboardKeyReleasedEvent::KeyboardKeyReleasedEvent(unsigned int releasedKey) : KeyboardKeyEvent(releasedKey,0)
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