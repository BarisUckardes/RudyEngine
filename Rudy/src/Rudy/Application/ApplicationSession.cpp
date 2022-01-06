#include "ApplicationSession.h"
#include <Rudy/World/World.h>
namespace Rudy
{
	GENERATE_REFLECTABLE_TYPE(ApplicationSession);
	ApplicationSession::ApplicationSession(GraphicsDevice* defaultDevice)
	{
		m_DefaultDevice = defaultDevice;
	}
	Array<World*> ApplicationSession::GetWorlds() const
	{
		return m_Worlds;
	}
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

	World* ApplicationSession::LoadViaAsset(const Guid& worldID)
	{
		return nullptr;
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

	GraphicsDevice* ApplicationSession::GetDefaultGraphicsDevice() const
	{
		return m_DefaultDevice;
	}

	void ApplicationSession::DestroyCore()
	{

	}

}