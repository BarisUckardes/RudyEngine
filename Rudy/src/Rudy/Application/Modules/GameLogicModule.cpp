#include "GameLogicModule.h"
#include <Rudy/Memory/Array.h>
#include <Rudy/World/World.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/World/Views/WorldLogicView.h>
#include <Rudy/World/Resolver/Resolvers/LogicResolver.h>
namespace Rudy
{
	void GameLogicModule::OnAttach()
	{

	}
	void GameLogicModule::OnUpdate()
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
			WorldLogicView* logicView = world->GetView<WorldLogicView>();

			/*
			* Get logic view resolvers
			*/
			Array<LogicResolver*> logicResolvers = logicView->GetLogicResolvers();

			/*
			* Iterate logic resolvers
			*/
			for (int resolverIndex = 0; resolverIndex < logicResolvers.GetCursor(); resolverIndex++)
			{
				logicResolvers[resolverIndex]->Resolve();
			}

		}

	}
	void GameLogicModule::OnDetach()
	{

	}
	void GameLogicModule::OnReceiveApplicationEvent(Event* event)
	{
	}
}