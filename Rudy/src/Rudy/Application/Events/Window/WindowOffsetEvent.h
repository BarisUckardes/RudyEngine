#pragma once
#include <Rudy/Application/Events/Event.h>
#include <Rudy/Mathematics/Vector2i.h>

namespace Rudy
{
	/// <summary>
	/// Event wrapper for window offset
	/// </summary>
	class RUDY_API WindowOffsetEvent : public Event
	{
	public:
		WindowOffsetEvent(const Vector2i& offset);
		~WindowOffsetEvent() = default;

		FORCEINLINE Vector2i GetOffset() const;

	protected:
		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;

	private:
		Vector2i m_Offset;
	};

}