#pragma once
#include <Rudy/Events/Event.h>

namespace Rudy
{
	class RUDY_API EventDispatcher
	{
	public:
		EventDispatcher(Event& event);
		~EventDispatcher() = default;

		template<typename TEvent>
		bool Dispatch();
	private:
		Event& m_Event;
	};


}