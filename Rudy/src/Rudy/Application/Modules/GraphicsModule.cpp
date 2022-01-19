#include "GraphicsModule.h"
#include <Rudy/World/World.h>
#include <Rudy/World/Views/WorldGraphicsView.h>
#include <Rudy/World/Resolver/Resolvers/GraphicsResolver.h>
#include <Rudy/Application/ApplicationSession.h>
namespace Rudy
{
	void GraphicsModule::OnAttach()
	{

	}
	void GraphicsModule::OnUpdate()
	{
		/*
		* Get all the worlds
		*/
		Array<World*> worlds = GetOwnerSession()->GetWorlds();

		/*
		* Iterate each world
		*/
		for (int worldIndex = 0; worldIndex < worlds.GetCursor(); worldIndex++)
		{
			/*
			* Get world
			*/
			World* world = worlds[worldIndex];

			/*
			* Get logic view
			*/
			WorldGraphicsView* graphicsView = world->GetView<WorldGraphicsView>();

			/*
			* Get logic view resolvers
			*/
			Array<GraphicsResolver*> graphicsResolvers = graphicsView->GetGraphicsResolvers();

			/*
			* Iterate logic resolvers
			*/
			for (int resolverIndex = 0; resolverIndex < graphicsResolvers.GetCursor(); resolverIndex++)
			{
				graphicsResolvers[resolverIndex]->Resolve();
			}

		}
	}
	void GraphicsModule::OnDetach()
	{

	}
	void GraphicsModule::OnReceiveApplicationEvent(Event* event)
	{

	}
}