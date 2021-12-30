#include "TestModule.h"
#include <Rudy/World/World.h>
#include <Rudy/Entity/Entity.h>
#include <Rudy/Component/Built-in/Spatial.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/World/Views/WorldLogicView.h>
#include <stdio.h>
#include <Rudy/Resolver/Custom Resolvers/DefaultLogicResolver.h>
namespace Rudy
{
	void TestModule::OnAttach()
	{
		/*
		* Create new world
		*/
		World* world = GetOwnerSession()->CreateWorld();

		/*
		* Create logic view
		*/
		WorldLogicView* view = world->RegisterView<WorldLogicView>();

		/*
		* Register default logic resolver
		*/
		view->RegisterResolver<DefaultLogicResolver>();

		/*
		* Create entity
		*/
		Entity* entity = world->CreateEntity();
		entity->SetName("MAH NAME");
		Spatial* spatial = entity->GetComponent<Spatial>();
		spatial->SetPosition(Vector3f(500, 5, 5));
		Vector3f pos = entity->GetSpatial()->GetPosition();
		
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