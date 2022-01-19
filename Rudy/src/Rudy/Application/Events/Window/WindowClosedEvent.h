#pragma once
#include <Rudy/Application/Events/Event.h>

namespace Rudy
{
	class RUDY_API WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() = default;
		~WindowClosedEvent() = default;

		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;

	};


}