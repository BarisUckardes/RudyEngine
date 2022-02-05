#include "WorldGraphicsView.h"
#include <Rudy/Graphics/Components/ObserverComponent.h>
#include <Rudy/World/Resolver/Resolvers/GraphicsResolver.h>
namespace Rudy
{
	GENERATE_REFLECTABLE_TYPE(WorldGraphicsView);
	void WorldGraphicsView::RegisterObserver(ObserverComponent* observer)
	{
		/*
		* Broadcast to all resolvers
		*/
		for (int i = 0; i < m_GraphicsResolvers.GetCursor(); i++)
			m_GraphicsResolvers[i]->OnRegisterObserver(observer);
	}
	void WorldGraphicsView::RemoveObserver(ObserverComponent* observer)
	{
		/*
		* Broadcast to all resolvers
		*/
		for (int i = 0; i < m_GraphicsResolvers.GetCursor(); i++)
			m_GraphicsResolvers[i]->OnRemoveObserver(observer);
	}
	void WorldGraphicsView::RegisterGraphicsObject(Component* component)
	{
		/*
		* Get component id
		*/
		ReflectionType* componentType = component->GetType();

		/*
		* Iterate each observer
		*/
		for (int resolverIndex = 0; resolverIndex < m_GraphicsResolvers.GetCursor(); resolverIndex++)
		{
			/*
			* Get resolver
			*/
			GraphicsResolver* resolver = m_GraphicsResolvers[resolverIndex];

			/*
			* Get register informations
			*/
			Array<GraphicsObjectRegisterInfo>& registerInformations = m_RegisterInformations[resolverIndex];

			/*
			* Itereate register informations
			*/
			for (int infoIndex = 0; infoIndex < m_RegisterInformations.GetCursor(); infoIndex++)
			{
				/*
				* Get register informations
				*/
				GraphicsObjectRegisterInfo& registerInformation = registerInformations[infoIndex];

				/*
				* Validate if there is a match
				*/
				if (registerInformation.GetTargetType() == componentType)
				{
					registerInformation.Register(component);
				}
			}

		}
	}
	void WorldGraphicsView::RemoveGraphicsObject(Component* component)
	{
		/*
		* Get component id
		*/
		ReflectionType* componentType = component->GetType();

		/*
		* Iterate each observer
		*/
		for (int resolverIndex = 0; resolverIndex < m_GraphicsResolvers.GetCursor(); resolverIndex++)
		{
			/*
			* Get resolver
			*/
			GraphicsResolver* resolver = m_GraphicsResolvers[resolverIndex];

			/*
			* Get register informations
			*/
			Array<GraphicsObjectRegisterInfo>& registerInformations = m_RegisterInformations[resolverIndex];

			/*
			* Itereate register informations
			*/
			for (int infoIndex = 0; infoIndex < m_RegisterInformations.GetCursor(); infoIndex++)
			{
				/*
				* Get register informations
				*/
				GraphicsObjectRegisterInfo& registerInformation = registerInformations[infoIndex];

				/*
				* Validate if there is a match
				*/
				if (registerInformation.GetTargetType() == componentType)
				{
					registerInformation.Remove(component);
				}
			}
		}

	}
	Array<GraphicsResolver*> WorldGraphicsView::GetGraphicsResolvers() const
	{
		return m_GraphicsResolvers;
	}

	void WorldGraphicsView::RegisterResolverCore(IWorldResolver* resolver)
	{
		/*
		* Register resolver
		*/
		GraphicsResolver* graphicsResolver = (GraphicsResolver*)resolver;
		m_GraphicsResolvers.Add(graphicsResolver);

		/*
		* Get graphics object register informations
		*/
		Array<GraphicsObjectRegisterInfo> registerInformations = graphicsResolver->GetRegisterInformations();

		/*
		* Register informations
		*/
		m_RegisterInformations.Add(registerInformations);
	}

	void WorldGraphicsView::RemoveResolverCore(IWorldResolver* resolver)
	{
	}

}