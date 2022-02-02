#include "World.h"
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/World/Entity/Entity.h>
#include <Rudy/World/WorldView.h>
#include <Rudy/Reflection/Type/ReflectionType.h>
namespace Rudy
{
	GENERATE_REFLECTABLE_TYPE(World);
	World::World(ApplicationSession* targetSession)
	{
		/*
		* Set owner session
		*/
		m_OwnerSession = targetSession;

	}

	Array<WorldView*> World::GetViews() const
	{
		return m_Views;
	}
	Array<Entity*> World::GetEntities() const
	{
		return m_Entities;
	}
	Entity* World::CreateEntity()
	{
		/*
		* Create new entity
		*/
		Entity* entity = new Entity();

		/*
		* Set owner world
		*/
		entity->m_OwnerWorld = this;

		/*
	    * Create and register spatial component
	    */
		Spatial* spatial = entity->CreateComponent<Spatial>();

		/*
		* Set spatial
		*/
		entity->m_Spatial = spatial;

		/*
		* Register it to the component list
		*/
		entity->m_Components.Add((Component*)spatial);

		return entity;
	}
	GraphicsDevice* World::GetDefaultGraphicsDevice() const
	{
		return m_OwnerSession->GetDefaultGraphicsDevice();
	}
	void World::DestroyCore()
	{
		/*
		* Destroy all entites
		*/
		for (int i = 0; i < m_Entities.GetCursor(); i++)
		{
			/*
			* Get entity
			*/
			Entity* entity = m_Entities[i];

			/*
			* Destroy entity
			*/
			entity->Destroy();

			/*
			* Free from memory
			*/
			delete entity;
		}
		m_Entities.Clear();

		/*
		* Destroy views
		*/
		for (int i = 0; i < m_Views.GetCursor(); i++)
		{
			/*
			* Get view
			*/
			WorldView* view = m_Views[i];

			/*
			* Destory view
			*/
			view->Destroy();

			/*
			* Free from memory
			*/
			delete view;
		}
		m_Views.Clear();

		/*
		* Remove this world from the world
		*/
		m_OwnerSession->RemoveWorld(this);
	}
}