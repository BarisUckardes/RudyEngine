#include "MousePositionChangedEvent.h"

namespace Rudy
{
	MousePositionChangedEvent::MousePositionChangedEvent(const Vector2i& position)
	{
		m_Position = position;
	}
	Vector2i MousePositionChangedEvent::GetPosition() const
	{
		return m_Position;
	}
	EventType MousePositionChangedEvent::GetEventType() const
	{
		return EventType::MousePositionChanged;
	}
	String MousePositionChangedEvent::GetAsString() const
	{
		return "Mouse position changed event";
	}
}