#include "RudyObject.h"

namespace Rudy
{

	String RudyObject::GetName() const
	{
		return m_Name;
	}
	bool RudyObject::IsDestroyed() const
	{
		return m_Destroyed;
	}
	void RudyObject::SetName(const String& name)
	{
		m_Name = name;
	}
	void RudyObject::Destroy()
	{
		/*
		* Call destory implementation
		*/
		DestroyCore();

		/*
		* Mark this object destroyed
		*/
		m_Destroyed = true;
	}
	RudyObject::RudyObject()
	{

	}
}