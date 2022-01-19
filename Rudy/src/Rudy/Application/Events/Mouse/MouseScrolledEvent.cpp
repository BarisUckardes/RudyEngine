#include "MouseScrolledEvent.h"

namespace Rudy
{
    MouseScrolledEvent::MouseScrolledEvent(const Vector2f& amount)
    {
        m_Amount = amount;
    }
    Vector2f MouseScrolledEvent::GetAmount() const
    {
        return m_Amount;
    }
    EventType MouseScrolledEvent::GetEventType() const
    {
        return EventType::MouseScrolled;
    }
    String MouseScrolledEvent::GetAsString() const
    {
        return "Mouse scrolled";
    }
}