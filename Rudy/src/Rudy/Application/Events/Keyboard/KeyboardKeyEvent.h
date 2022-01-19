#pragma once
#include <Rudy/Application/Events/Event.h>

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

		/// <summary>
		/// Returns the repeat count for the related key
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetRepeatCount() const;
	protected:
		KeyboardKeyEvent(unsigned int relatedKey,unsigned int repeatCount);
		~KeyboardKeyEvent() = default;
	private:
		unsigned int m_RelatedKey;
		unsigned int m_RepeatCount;
	};
}