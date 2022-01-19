#include "IWorldResolver.h"

namespace Rudy
{
	World* IWorldResolver::GetOwnerWorld() const
	{
		return m_OwnerWorld;
	}
	void IWorldResolver::SetOwnerWorld(World* ownerWorld)
	{
		m_OwnerWorld = ownerWorld;
	}
}