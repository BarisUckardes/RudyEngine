#include "ApplicationSession.h"
#include <Rudy/World/World.h>
namespace Rudy
{


	World* ApplicationSession::CreateWorld()
	{
		/*
		* Create new world
		*/
		World* world = new World(this);

		/*
		* Register
		*/
		m_Worlds.Add(world);

		return world;
	}

	void ApplicationSession::RemoveWorld(World* world)
	{
		/*
		* Try find world
		*/
		for (int i = 0; i < m_Worlds.GetCursor(); i++)
		{
			/*
			* Get world
			*/
			World* world = m_Worlds[i];

			/*
			* Destroy the world
			*/
			world->Destroy();

			/*
			* Free the memory
			*/
			delete world;
			return;
		}

	}

	void ApplicationSession::DestroyCore()
	{

	}

}