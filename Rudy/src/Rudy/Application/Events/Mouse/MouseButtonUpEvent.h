#pragma once
#include <Rudy/Application/Events/Mouse/MouseButtonEvent.h>

namespace Rudy
{
	/// <summary>
	/// Mouse button up event wrapper
	/// </summary>
	class RUDY_API MouseButtonUpEvent : public MouseButtonEvent
	{
	public:
		MouseButtonUpEvent(int button);
		~MouseButtonUpEvent() = default;

	protected:
		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;
	};
}