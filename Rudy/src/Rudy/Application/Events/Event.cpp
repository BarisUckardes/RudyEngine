#include "Event.h"

namespace Rudy
{
	bool Event::IsHandled() const
	{
		return m_Handled;;
	}

	void Event::MarkHandled()
	{
		m_Handled = true;
	}

}