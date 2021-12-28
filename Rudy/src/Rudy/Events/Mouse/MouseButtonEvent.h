#pragma once
#include <Rudy/Events/Event.h>

namespace Rudy
{
	/// <summary>
	/// Base mouse button event
	/// </summary>
	class RUDY_API MouseButtonEvent : public Event
	{
	protected:
		MouseButtonEvent(int button);
		~MouseButtonEvent() = default;
		
		/// <summary>
		/// Returns the button id
		/// </summary>
		/// <returns></returns>
		FORCEINLINE int GetButton() const;
	private:
		int m_Button;
	};
}