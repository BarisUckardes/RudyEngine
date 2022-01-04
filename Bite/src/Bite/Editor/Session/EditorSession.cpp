#include "EditorSession.h"

namespace Bite
{
	EditorSession::EditorSession(Rudy::ApplicationSession* applicationSession)
	{
		m_ApplicationSession = applicationSession;
	}
	EditorSession::~EditorSession()
	{
		m_ApplicationSession = nullptr;
	}
	Rudy::ApplicationSession* EditorSession::GetApplictionSession() const
	{
		return m_ApplicationSession;
	}
}