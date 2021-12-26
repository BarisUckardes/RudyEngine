#pragma once
#include <Rudy/Events/Keyboard/KeyboardKeyEvent.h>

namespace Rudy
{
	/// <summary>
	/// Event class for keyboard key down
	/// </summary>
	class RUDY_API KeyboardKeyDownEvent : KeyboardKeyEvent
	{
	public:
		KeyboardKeyDownEvent(unsigned int downKey);
		~KeyboardKeyDownEvent() = default;

		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;
	};

}
