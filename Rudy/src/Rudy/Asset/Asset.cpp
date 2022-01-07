#include "Asset.h"

namespace Rudy
{
	Asset::Asset(RudyObject* assetObject, const Guid& id)
	{
		m_LoadedObject = assetObject;
		m_ID = id;
	}
	RudyObject* Asset::GetLoadedObject() const
	{
		return m_LoadedObject;
	}
	Guid Asset::GetID() const
	{
		return m_ID;
	}
	Asset::~Asset()
	{
		/*
		* Destory if its not destroyed
		*/
		if (!m_LoadedObject->IsDestroyed())
			m_LoadedObject->Destroy();

		/*
		* Delete heap object
		*/
		delete m_LoadedObject;

		m_LoadedObject = nullptr;
	}
}