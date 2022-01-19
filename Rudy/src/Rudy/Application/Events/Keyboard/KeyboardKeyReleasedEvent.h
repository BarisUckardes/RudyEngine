#pragma once
#include <Rudy/Application/Events/Keyboard/KeyboardKeyEvent.h>

namespace Rudy
{
	/// <summary>
	/// Event class for keyboard key released
	/// </summary>
	class RUDY_API KeyboardKeyReleasedEvent : public KeyboardKeyEvent
	{
	public:
		KeyboardKeyReleasedEvent(unsigned int releasedKey);
		~KeyboardKeyReleasedEvent() = default;

		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;

	};
}