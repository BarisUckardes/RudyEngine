#include "DefaultLogicResolver.h"
#include <Rudy/World/Component/Component.h>
#include <stdio.h>
namespace Rudy
{
	DefaultLogicResolver::DefaultLogicResolver()
	{
		m_RegisterPendingComponents.Reserve(100);
		m_RemovePendingComponents.Reserve(100);
	}
	void DefaultLogicResolver::Resolve()
	{
		/*
		* Invalidate components
		*/
		InvalidatePendings();

		/*
		* Update each component
		*/
		for (int i = 0; i < m_ActiveComponents.GetCursor(); i++)
		{
			m_ActiveComponents[i]->OnUpdate();
		}
	}
	void DefaultLogicResolver::OnRegisterComponent(Component* component)
	{
		m_RegisterPendingComponents.Add(component);
	}
	void DefaultLogicResolver::OnRemoveComponent(Component* component)
	{
		m_RemovePendingComponents.Add(component);
	}
	void DefaultLogicResolver::InvalidatePendings()
	{
		/*
		* Remove pending components
		*/
		for (int i = 0; i < m_RemovePendingComponents.GetCursor(); i++)
		{
			/*
			* Get component
			*/
			Component* component = m_RemovePendingComponents[i];

			/*
			* Remove from the active components;
			*/
			m_ActiveComponents.Remove(component);

			/*
			* Remove from the register pending components;
			*/
			m_RemovePendingComponents.Remove(component);

			/*
			* Call detach method
			*/
			component->OnDetach();
		}
		m_RemovePendingComponents.Clear();

		/*
		* Register pending components
		*/
		for (int i = 0; i < m_RegisterPendingComponents.GetCursor(); i++)
		{
			/*
			* Get component
			*/
			Component* component = m_RegisterPendingComponents[i];

			/*
			* Register component
			*/
			m_ActiveComponents.Add(component);

			/*
			* Call attach method
			*/
			component->OnAttach();
		}
		m_RegisterPendingComponents.Clear();
	}
}