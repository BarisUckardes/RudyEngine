#pragma once
#include <Rudy/Events/Event.h>
#include <functional>
namespace Rudy
{
	class RUDY_API EventDispatcher
	{
		template<typename TEvent>
		using PlatformEventFunction = std::function<bool(TEvent&)>;
	public:
		EventDispatcher(Event& event);
		~EventDispatcher() = default;

		template<typename TEvent>
		bool Dispatch(PlatformEventFunction<TEvent> function)
		{
			return false;
		}
	private:
		Event& m_Event;
	};


}