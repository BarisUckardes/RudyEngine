#include "EditorApplication.h"
#include <Rudy/Windowing/Window.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Application/Modules/GameInputModule.h>
#include <Rudy/Application/Modules/TestModule.h>
#include <Rudy/Application/Modules/GameLogicModule.h>
#include <Rudy/Application/Modules/GraphicsModule.h>
#include <Bite/Module/BiteModule.h>
#include <Bite/GUI/Module/MainMenu/MainMenuBarGUIModule.h>
namespace EditorLauncher
{
	EditorApplication::EditorApplication(const Rudy::String& title, unsigned int offsetX, unsigned int offsetY, unsigned int sizeX, unsigned int sizeY) : Rudy::Application(Rudy::WindowCreateParameters(title,Rudy::Vector2i(offsetX,offsetY),Rudy::Vector2i(sizeX,sizeY)))
	{
		/*
		* Create gui module list
		*/
		Rudy::Array<Bite::GUIModule*> guiModules;
		guiModules.Add(new Bite::MainMenuBarGUIModule());

		/*
		* Register editor application modules
		*/
		RegisterModule<Rudy::GameInputModule>();
		RegisterModule<Rudy::TestModule>();
		RegisterModule<Rudy::GameLogicModule>();
		RegisterModule<Rudy::GraphicsModule>();
		RegisterModule<Bite::BiteModule>(guiModules);
	}

	void EditorApplication::RunEditor()
	{
		Run();
	}

	EditorApplication::~EditorApplication()
	{

	}
}