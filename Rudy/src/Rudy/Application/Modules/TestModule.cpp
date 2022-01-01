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
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Graphics/Buffer/VertexBuffer.h>
#include <Rudy/Graphics/Buffer/IndexBuffer.h>
#include <Rudy/Graphics/Shader/Shader.h>
#include <Rudy/Graphics/Shader/ShaderProgram.h>
#include <Rudy/Mathematics/Vector2f.h>
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

		/*
		* Create vertex buffer
		*/
		VertexBuffer* vertexBuffer = GetOwnerSession()->GetDefaultGraphicsDevice()->CreateVertexBuffer();

		Array<VertexLayoutElement> vertexLayoutElements;
		vertexLayoutElements.Add(VertexLayoutElement(VertexLayoutDataType::Float2, "aPosition"));

		VertexLayout vertexLayout(vertexLayoutElements);

		vertexBuffer->Initialize(vertexLayout);

		Array<Vector2f> vertexes;
		vertexes.Add(Vector2f(-0.5f, -0.5f));
		vertexes.Add(Vector2f(0.5f, -0.5f));
		vertexes.Add(Vector2f(0.0f, 0.5f));

		vertexBuffer->SetData((unsigned char*)vertexes.GetData(), sizeof(Vector2f), vertexes.GetCursor());

		/*
		* Create index buffer
		*/
		IndexBuffer* indexBuffer = GetOwnerSession()->GetDefaultGraphicsDevice()->CreateIndexBuffer();
		
		Array<unsigned int> triangles;
		triangles.Add(0);
		triangles.Add(1);
		triangles.Add(2);

		indexBuffer->SetData((unsigned char*)triangles.GetData(), triangles.GetCursor(), sizeof(unsigned int));

		/*
		* Create shaders
		*/
		Shader* vertexShader = GetOwnerSession()->GetDefaultGraphicsDevice()->CreateShader(ShaderStage::Vertex);
		Shader* fragmenShader = GetOwnerSession()->GetDefaultGraphicsDevice()->CreateShader(ShaderStage::Fragment);
		vertexShader->Compile("yasag");
		fragmenShader->Compile("yayay");

		/*
		* Create shader program
		*/
		Array<Shader*> shaders;
		shaders.Add(vertexShader);
		shaders.Add(fragmenShader);

		ShaderProgram* shaderProgram = GetOwnerSession()->GetDefaultGraphicsDevice()->CreateShaderProgram();
		shaderProgram->LinkProgram(shaders);

		/*
		* Set deferred renderable properties
		*/
		renderable->m_VertexBuffer = vertexBuffer;
		renderable->m_IndexBuffer = indexBuffer;
		renderable->m_Program = shaderProgram;
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