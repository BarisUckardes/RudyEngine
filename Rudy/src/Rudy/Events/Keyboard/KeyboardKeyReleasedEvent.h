#pragma once
#include <Rudy/Events/Keyboard/KeyboardKeyEvent.h>

namespace Rudy
{
	/// <summary>
	/// Event class for keyboard key released
	/// </summary>
	class RUDY_API KeyboardKeyReleasedEvent : KeyboardKeyEvent
	{
	public:
		KeyboardKeyReleasedEvent(unsigned int releasedKey);
		~KeyboardKeyReleasedEvent() = default;

		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;

	};
}