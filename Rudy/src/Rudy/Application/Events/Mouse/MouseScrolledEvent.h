#pragma once
#include <Rudy/Application/Events/Event.h>
#include <Rudy/Mathematics/Vector2f.h>

namespace Rudy
{
	/// <summary>
	/// Mouse scrolled event wrapper
	/// </summary>
	class RUDY_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const Vector2f& amount);
		~MouseScrolledEvent() = default;

		/// <summary>
		/// Returns the amount of scroll
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector2f GetAmount() const;

	protected:
		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;
	private:
		Vector2f m_Amount;
	};

}
