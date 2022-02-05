#include "RudyObject.h"

namespace Rudy
{

	String RudyObject::GetName() const
	{
		return m_Name;
	}
	void RudyObject::SetName(const String& name)
	{
		m_Name = name;
	}
	RudyObject::RudyObject()
	{

	}
}