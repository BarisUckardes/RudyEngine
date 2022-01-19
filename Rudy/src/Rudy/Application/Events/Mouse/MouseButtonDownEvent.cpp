#include "MouseButtonDownEvent.h"

namespace Rudy
{
	MouseButtonDownEvent::MouseButtonDownEvent(int button) : MouseButtonEvent(button)
	{
	}
	EventType MouseButtonDownEvent::GetEventType() const
	{
		return EventType::MouseButtonDown;
	}
	String MouseButtonDownEvent::GetAsString() const
	{
		return "Mouse button down event";
	}
}