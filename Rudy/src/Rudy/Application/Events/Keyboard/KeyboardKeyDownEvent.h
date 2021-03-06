#pragma once
#include <Rudy/Application/Events/Keyboard/KeyboardKeyEvent.h>

namespace Rudy
{
	/// <summary>
	/// Event class for keyboard key down
	/// </summary>
	class RUDY_API KeyboardKeyDownEvent : public KeyboardKeyEvent
	{
	public:
		KeyboardKeyDownEvent(unsigned int downKey,unsigned int repeatCount);
		~KeyboardKeyDownEvent() = default;

		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;
	};

}
