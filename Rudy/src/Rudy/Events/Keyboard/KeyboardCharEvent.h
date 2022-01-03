#pragma once
#include <Rudy/Events/Keyboard/KeyboardKeyEvent.h>

namespace Rudy
{
	class RUDY_API KeyboardCharEvent : public KeyboardKeyEvent
	{
	public:
		KeyboardCharEvent(unsigned int relatedKey);
		~KeyboardCharEvent() = default;

		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;
	};


}