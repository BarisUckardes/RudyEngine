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
	void EditorSession::SetProject(const Rudy::String& name, unsigned int major, unsigned int minor, const Rudy::Guid& id)
	{
		/*
		* Set project properties
		*/
		m_ProjectProperties.Name = name;
		m_ProjectProperties.MajorVersion = major;
		m_ProjectProperties.MinorVersion = minor;
		m_ProjectProperties.ID = id;
	}
}