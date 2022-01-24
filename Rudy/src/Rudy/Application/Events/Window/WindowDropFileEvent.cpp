#include "WindowDropFileEvent.h"

namespace Rudy
{
	WindowDropFileEvent::WindowDropFileEvent(const Array<String>& drops)
	{
		m_DropPaths = drops;
	}
	Array<String> WindowDropFileEvent::GetDropFilePaths() const
	{
		return m_DropPaths;
	}
	EventType WindowDropFileEvent::GetEventType() const
	{
		return EventType::WindowFileDrop;
	}
	String WindowDropFileEvent::GetAsString() const
	{
		return "Window file drop event";
	}
}