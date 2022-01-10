#include "EditorCommand.h"

namespace Bite
{
	EditorCommand::~EditorCommand()
	{
		m_OwnerSession = nullptr;
	}
	EditorSession* EditorCommand::GetOwnerSession() const
	{
		return m_OwnerSession;
	}
	void EditorCommand::SetOwnerSession(EditorSession* session)
	{
		m_OwnerSession = session;
	}
}