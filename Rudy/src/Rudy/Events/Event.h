#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Events/EventType.h>
#include <Rudy/Memory/String.h>
namespace Rudy
{
	/// <summary>
	/// Base event class for all the application events
	/// </summary>
	class RUDY_API Event
	{
	public:
		Event() = default;
		~Event() = default;

		/// <summary>
		/// Returns whether this event is handled(consumed).
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsHandled() const;

		/// <summary>
		/// Returns the event type of this event
		/// </summary>
		/// <returns></returns>
		virtual EventType GetEventType() const = 0;

		/// <summary>
		/// Returns this event as a string representation
		/// </summary>
		/// <returns></returns>
		virtual String GetAsString() const = 0;
	private:
		bool m_Handled;
	};
}