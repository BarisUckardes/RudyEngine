#pragma once
#include <Rudy/Events/Event.h>
#include <Rudy/Mathematics/Vector2i.h>
namespace Rudy
{
	/// <summary>
	/// Event class for window resize
	/// </summary>
	class RUDY_API WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(const Vector2i& size);
		~WindowResizedEvent() = default;

		/// <summary>
		/// Returns the size which this event holds
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector2i GetSize() const;
	private:
		Vector2i m_Size;

		// Inherited via Event
		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;
	};

}
