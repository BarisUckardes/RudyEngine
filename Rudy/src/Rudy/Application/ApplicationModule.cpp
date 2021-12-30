#include "ApplicationModule.h"

namespace Rudy
{
	ApplicationSession* ApplicationModule::GetOwnerSession() const
	{
		return m_OwnerSession;
	}
	void ApplicationModule::SetOwnerSession(ApplicationSession* session)
	{
		m_OwnerSession = session;
	}
}