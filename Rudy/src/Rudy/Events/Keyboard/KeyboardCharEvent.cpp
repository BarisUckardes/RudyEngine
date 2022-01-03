#include "KeyboardCharEvent.h"

namespace Rudy
{
	EventType KeyboardCharEvent::GetEventType() const
	{
		return EventType::KeyboardChar;
	}

	String KeyboardCharEvent::GetAsString() const
	{
		return "Key char input event";
	}

}