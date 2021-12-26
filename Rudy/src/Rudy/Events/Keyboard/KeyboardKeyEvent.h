#pragma once
#include <Rudy/Events/Event.h>

namespace Rudy
{
	/// <summary>
	/// The base class for all the keyboard events
	/// </summary>
	class RUDY_API KeyboardKeyEvent : public Event
	{
	public:
		/// <summary>
		/// Returns the related key for this keyboard event
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetRelatedKey() const;
	protected:
		KeyboardKeyEvent(unsigned int relatedKey);
		~KeyboardKeyEvent() = default;
	private:
		unsigned int m_RelatedKey;
	};
}