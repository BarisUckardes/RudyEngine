#include "WorldLogicView.h"
#include <Rudy/World/Resolver/Resolvers/LogicResolver.h>
#include <Rudy/Reflection/Type/ReflectionType.h>
namespace Rudy
{
	GENERATE_REFLECTABLE_TYPE(WorldLogicView);
	Array<Component*> WorldLogicView::GetComponents() const
	{
		return m_Components;
	}

	Array<LogicResolver*> WorldLogicView::GetLogicResolvers() const
	{
		return m_Resolvers;
	}

	void WorldLogicView::RegisterComponent(Component* component)
	{
		/*
		* Iterate each resolver and register component
		*/
		for (int i = 0; i < m_Resolvers.GetCursor(); i++)
		{
			m_Resolvers[i]->OnRegisterComponent(component);
		}
	}

	void WorldLogicView::RemoveComponent(Component* component)
	{
		/*
		* Iterate each resolver and remove component
		*/
		for (int i = 0; i < m_Resolvers.GetCursor(); i++)
		{
			m_Resolvers[i]->OnRegisterComponent(component);
		}
	}


	void WorldLogicView::RegisterResolverCore(IWorldResolver* resolver)
	{
		m_Resolvers.Add((LogicResolver*)resolver);
	}

	void WorldLogicView::RemoveResolverCore(IWorldResolver* resolver)
	{
		m_Resolvers.Remove((LogicResolver*)resolver);
	}

}