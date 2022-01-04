#include "GUIModule.h"

namespace Bite
{
	GUIModule::~GUIModule()
	{

	}
	EditorSession* GUIModule::GetOwnerSession() const
	{
		return m_OwnerSession;
	}
	void GUIModule::SetOwnerSession(EditorSession* session)
	{
		m_OwnerSession = session;
	}
}