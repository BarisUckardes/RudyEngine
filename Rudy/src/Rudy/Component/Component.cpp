#include "Component.h"
#include <Rudy/Entity/Entity.h>
namespace Rudy
{
	Component::~Component()
	{
		m_OwnerEntity = nullptr;
	}
	void Component::SetOwnerEntity(Entity* ownerEntity)
	{
		m_OwnerEntity = ownerEntity;
	}
	Entity* Component::GetOwnerEntity() const
	{
		return m_OwnerEntity;
	}
	void Component::OnUpdate()
	{
	}
	void Component::OnAttach()
	{
	}
	void Component::OnDetach()
	{
	}
	
}