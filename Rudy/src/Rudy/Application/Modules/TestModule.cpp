#include "TestModule.h"
#include <Rudy/World/World.h>
#include <Rudy/World/Entity/Entity.h>
#include <Rudy/World/Component/Built-in/Spatial.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/World/Views/WorldLogicView.h>
#include <stdio.h>
#include <Rudy/World/Resolver/Custom Resolvers/DefaultLogicResolver.h>
#include <Rudy/World/Views/WorldGraphicsView.h>
#include <Rudy/World/Resolver/Custom Resolvers/DeferredGraphicsResolver.h>
#include <Rudy/Buit-in/Deferred/DeferredRenderable.h>
#include <Rudy/World/Component/Built-in/PerspectiveObserver.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Graphics/Buffer/VertexBuffer.h>
#include <Rudy/Graphics/Buffer/IndexBuffer.h>
#include <Rudy/Graphics/Shader/Shader.h>
#include <Rudy/Graphics/Shader/ShaderProgram.h>
#include <Rudy/Mathematics/Vector2f.h>
namespace Rudy
{
	struct VertexData
	{
		VertexData() = default;
		VertexData(float x, float y,float u,float v, float r, float g, float b, float a)
		{
			Position = Vector2f(x, y);
			Uv = Vector2f(u, v);
			Color = ColorRgba(r, g, b, a);
		}
		~VertexData() = default;
		Vector2f Position;
		Vector2f Uv;
		ColorRgba Color;
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

		/*
		* Create vertex buffer
		*/
		VertexBuffer* vertexBuffer = GetOwnerSession()->GetDefaultGraphicsDevice()->CreateVertexBuffer();

		Array<VertexLayoutElement> vertexLayoutElements;
		vertexLayoutElements.Add(VertexLayoutElement(VertexLayoutDataType::Float2, "aPosition"));
		vertexLayoutElements.Add(VertexLayoutElement(VertexLayoutDataType::Float2, "aUv"));
		vertexLayoutElements.Add(VertexLayoutElement(VertexLayoutDataType::Float4, "aColor"));

		VertexLayout vertexLayout(vertexLayoutElements);

		vertexBuffer->Initialize(vertexLayout);

		Array<VertexData> vertexes;
		vertexes.Add(VertexData(-0.5f, -0.5f,0,0,1.0f,0.0f,0.0f,1.0f));
		vertexes.Add(VertexData(0.5f, -0.5f,0,0,0.0f,1.0f,0.0f,1.0f));
		vertexes.Add(VertexData(0.0f, 0.5f,0,0,0.0f,0.0f,1.0f,1.0f));

		vertexBuffer->SetData((unsigned char*)vertexes.GetData(), sizeof(VertexData), vertexes.GetCursor());

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
		String vertexSource;
		String fragmentSource;
		Shader* vertexShader = GetOwnerSession()->GetDefaultGraphicsDevice()->CreateShader(ShaderStage::Vertex);
		Shader* fragmenShader = GetOwnerSession()->GetDefaultGraphicsDevice()->CreateShader(ShaderStage::Fragment);
		vertexShader->Compile(
		"#version 450 core\n"
		"layout(location = 0) in vec2 aPosition;\n"
		"layout(location = 1) in vec2 aUv;\n"
		"layout(location = 2) in vec4 aColor;\n"
		"out vec4 f_Color;\n"
		"out vec2 f_Uv;\n"
		"void main()\n"
		
		"{\n"
			"gl_Position = vec4(aPosition.x, aPosition.y, 0.0, 1.0);\n"
			"f_Color = aColor;\n"
			"f_Uv = aUv;\n"
		"}\n");

		fragmenShader->Compile(
		"#version 450 core\n"
		"out vec4 FragColor;\n"
		"in vec4 f_Color;\n"
		"in vec2 f_Uv;\n"
		"uniform sampler2D f_Texture;\n"
		"void main()\n"
		"{\n"
			"FragColor = f_Color;\n"
		"}\n"
		);

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