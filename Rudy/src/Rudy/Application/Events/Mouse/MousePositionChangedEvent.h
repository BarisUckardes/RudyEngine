#pragma once
#include <Rudy/Application/Events/Event.h>
#include <Rudy/Mathematics/Vector2i.h>

namespace Rudy
{
	/// <summary>
	/// Mouse position changed event wrapper
	/// </summary>
	class RUDY_API MousePositionChangedEvent : public Event
	{
	public:
		MousePositionChangedEvent(const Vector2i& position);
		~MousePositionChangedEvent() = default;

		/// <summary>
		/// Returns the new position
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector2i GetPosition() const;
	protected:
		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;
	private:
		Vector2i m_Position;
	};
}