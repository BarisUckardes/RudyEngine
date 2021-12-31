#include "TestModule.h"
#include <Rudy/World/World.h>
#include <Rudy/Entity/Entity.h>
#include <Rudy/Component/Built-in/Spatial.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/World/Views/WorldLogicView.h>
#include <stdio.h>
#include <Rudy/Resolver/Custom Resolvers/DefaultLogicResolver.h>
#include <Rudy/World/Views/WorldGraphicsView.h>
#include <Rudy/Resolver/Custom Resolvers/DeferredGraphicsResolver.h>
#include <Rudy/Buit-in/Deferred/DeferredRenderable.h>
#include <Rudy/Component/Built-in/PerspectiveObserver.h>
namespace Rudy
{
	class abc
	{
	public:
		String str;
	};
	void TestModule::OnAttach()
	{
		/*
		* Create new world
		*/
		World* world = GetOwnerSession()->CreateWorld();

		/*
		* Create logic view
		*/
		WorldLogicView* logicView = world->RegisterView<WorldLogicView>();

		/*
		* Register default logic resolver
		*/
		logicView->RegisterResolver<DefaultLogicResolver>();

		/*
		* Create graphics view
		*/
		WorldGraphicsView* graphicsView = world->RegisterView<WorldGraphicsView>();

		/*
		* Register deferred renderer
		*/
		graphicsView->RegisterResolver<DeferredGraphicsResolver>();

		/*
		* Create  observer entity
		*/
		Entity* observerEntity = world->CreateEntity();
		observerEntity->SetName("Observer entity");
		PerspectiveObserver* perspectiveObserver = observerEntity->CreateComponent<PerspectiveObserver>();
		perspectiveObserver->SetName("PERS OBS");
		
		/*
		* Create deferred renderable entity
		*/
		Entity* defferredRenderableEntity = world->CreateEntity();
		defferredRenderableEntity->SetName("Deferred renderable entity");
		DeferredRenderable* renderable = defferredRenderableEntity->CreateComponent<DeferredRenderable>();
		renderable->SetName("#1 deferred renderable");
	}

	void TestModule::OnUpdate()
	{

	}

	void TestModule::OnDetach()
	{

	}

	void TestModule::OnReceiveApplicationEvent(Event* event)
	{

	}

}