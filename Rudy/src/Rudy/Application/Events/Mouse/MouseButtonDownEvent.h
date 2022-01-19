#pragma once
#include <Rudy/Application/Events/Mouse/MouseButtonEvent.h>

namespace Rudy
{
	/// <summary>
	/// Mouse button down event wrapper
	/// </summary>
	class RUDY_API MouseButtonDownEvent : public MouseButtonEvent
	{
	public:
		MouseButtonDownEvent(int button);
		~MouseButtonDownEvent() = default;

	protected:
		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;
	};

}
