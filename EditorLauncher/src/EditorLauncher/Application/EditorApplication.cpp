#include "EditorApplication.h"
#include <Rudy/Windowing/Window.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Application/Modules/GameInputModule.h>
#include <Rudy/Application/Modules/TestModule.h>
#include <Rudy/Application/Modules/GameLogicModule.h>
#include <Rudy/Application/Modules/GraphicsModule.h>
namespace EditorLauncher
{
	EditorApplication::EditorApplication(const Rudy::String& title, unsigned int offsetX, unsigned int offsetY, unsigned int sizeX, unsigned int sizeY) : Rudy::Application(Rudy::WindowCreateParameters(title,Rudy::Vector2i(offsetX,offsetY),Rudy::Vector2i(sizeX,sizeY)))
	{
		/*
		* Register editor application modules
		*/
		RegisterModule<Rudy::GameInputModule>();
		RegisterModule<Rudy::TestModule>();
		RegisterModule<Rudy::GameLogicModule>();
		RegisterModule<Rudy::GraphicsModule>();
	}

	void EditorApplication::RunEditor()
	{
		Run();
	}

	EditorApplication::~EditorApplication()
	{

	}
}