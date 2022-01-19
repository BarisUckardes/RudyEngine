#include "KeyboardKeyDownEvent.h"

namespace Rudy
{
   
    KeyboardKeyDownEvent::KeyboardKeyDownEvent(unsigned int downKey, unsigned int repeatCount) : KeyboardKeyEvent(downKey,repeatCount)
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