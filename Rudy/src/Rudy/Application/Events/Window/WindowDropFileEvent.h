#pragma once
#include <Rudy/Application/Events/Event.h>

namespace Rudy
{
	/// <summary>
	/// Event class for window drop file paths
	/// </summary>
	class RUDY_API WindowDropFileEvent : public Event
	{
	public:
		WindowDropFileEvent(const Array<String>& dropPaths);
		~WindowDropFileEvent() = default;

		/// <summary>
		/// Returns the drop file paths
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<String> GetDropFilePaths() const;

		virtual EventType GetEventType() const override;
		virtual String GetAsString() const override;
	private:
		Array<String> m_DropPaths;
	};

}
