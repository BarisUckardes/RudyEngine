#include "EditorApplication.h"
#include <Rudy/Application/Windowing/Window.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Application/Modules/GameInputModule.h>
#include <Rudy/Application/Modules/TestModule.h>
#include <Rudy/Application/Modules/GameLogicModule.h>
#include <Rudy/Application/Modules/GraphicsModule.h>
#include <Bite/Module/BiteModule.h>
#include <Bite/GUI/Module/MainMenu/MainMenuBarGUIModule.h>
#include <Bite/GUI/Module/Window/WindowGUIModule.h>
#include <Bite/Editor/Command/Commands/ProjectLoaderEditorCommand.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Asset/AssetDefinition.h>
#include <Rudy/Asset/AssetPackage.h>
namespace EditorLauncher
{
	EditorApplication::EditorApplication(const Rudy::String& projectFolderPath,const Rudy::String& title, unsigned int offsetX, unsigned int offsetY, unsigned int sizeX, unsigned int sizeY) : Rudy::Application(projectFolderPath,Rudy::WindowCreateParameters(title,Rudy::Vector2i(offsetX,offsetY),Rudy::Vector2i(sizeX,sizeY)))
	{
		/*
		* Create gui module list
		*/
		Rudy::Array<Bite::GUIModule*> guiModules;
		guiModules.Add(new Bite::MainMenuBarGUIModule());
		guiModules.Add(new Bite::WindowGUIModule());

		/*
		* Create editor commands
		*/
		Rudy::Array<Bite::EditorCommand*> commands;
		commands.Add(new Bite::ProjectLoaderEditorCommand(projectFolderPath));

		/*
		* Register editor application modules
		*/
		RegisterModule<Rudy::GameInputModule>();
		RegisterModule<Rudy::TestModule>();
		RegisterModule<Rudy::GameLogicModule>();
		RegisterModule<Rudy::GraphicsModule>();
		RegisterModule<Bite::BiteModule>(guiModules, commands);
	}

	void EditorApplication::RunEditor()
	{
		Run();
	}

	EditorApplication::~EditorApplication()
	{

	}
}