#pragma once
#include <Rudy/Application/Events/Event.h>

namespace Rudy
{
	/// <summary>
	/// Base mouse button event
	/// </summary>
	class RUDY_API MouseButtonEvent : public Event
	{
	public:
		/// <summary>
		/// Returns the button id
		/// </summary>
		/// <returns></returns>
		FORCEINLINE int GetButton() const;
	protected:
		MouseButtonEvent(int button);
		~MouseButtonEvent() = default;
	private:
		int m_Button;
	};
}