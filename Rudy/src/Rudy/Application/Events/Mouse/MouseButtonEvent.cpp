#include "MouseButtonEvent.h"

namespace Rudy
{
	MouseButtonEvent::MouseButtonEvent(int button)
	{
		m_Button = button;
	}
	int MouseButtonEvent::GetButton() const
	{
		return m_Button;
	}
}
