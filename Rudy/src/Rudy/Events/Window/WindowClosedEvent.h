#pragma once
#include <Rudy/Events/Event.h>

namespace Rudy
{
	class RUDY_API WindowClosedEvent : Event
	{
	public:
		WindowClosedEvent() = default;
		~WindowClosedEvent() = default;

		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;

	};


}