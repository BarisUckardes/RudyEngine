#include "KeyboardCharEvent.h"

namespace Rudy
{
	KeyboardCharEvent::KeyboardCharEvent(unsigned int relatedKey) : KeyboardKeyEvent(relatedKey,0)
	{
	}
	EventType KeyboardCharEvent::GetEventType() const
	{
		return EventType::KeyboardChar;
	}

	String KeyboardCharEvent::GetAsString() const
	{
		return "Key char input event";
	}

}