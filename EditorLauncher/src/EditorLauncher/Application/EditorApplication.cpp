#include "EditorApplication.h"
#include <Rudy/Windowing/Window.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Application/Modules/GameInputModule.h>
#include <Rudy/Application/Modules/TestModule.h>
#include <Rudy/Application/Modules/GameLogicModule.h>
#include <Rudy/Application/Modules/GraphicsModule.h>
#include <Bite/Module/BiteModule.h>
#include <Bite/GUI/Module/MainMenu/MainMenuBarGUIModule.h>
#include <Bite/GUI/Module/Window/WindowGUIModule.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
namespace EditorLauncher
{
	struct DataPack
	{
		unsigned int a, b, c;
	};
	EditorApplication::EditorApplication(const Rudy::String& title, unsigned int offsetX, unsigned int offsetY, unsigned int sizeX, unsigned int sizeY) : Rudy::Application(Rudy::WindowCreateParameters(title,Rudy::Vector2i(offsetX,offsetY),Rudy::Vector2i(sizeX,sizeY)))
	{
		/*
		* Create gui module list
		*/
		Rudy::Array<Bite::GUIModule*> guiModules;
		guiModules.Add(new Bite::MainMenuBarGUIModule());
		guiModules.Add(new Bite::WindowGUIModule());

		/*
		* Register editor application modules
		*/
		RegisterModule<Rudy::GameInputModule>();
		RegisterModule<Rudy::TestModule>();
		RegisterModule<Rudy::GameLogicModule>();
		RegisterModule<Rudy::GraphicsModule>();
		RegisterModule<Bite::BiteModule>(guiModules);

		DataPack data = { 399,999,1999 };
		unsigned char* dataPtr = (unsigned char*)&data;
		unsigned int size = sizeof(data);

		Rudy::Array<unsigned char> writtenBytes(dataPtr, size);

		Rudy::PlatformFile::Write("C:/Users/PC/Desktop/test/hello.rpackage", writtenBytes);

		Rudy::Array<unsigned char> readBytes;
		Rudy::PlatformFile::Read("C:/Users/PC/Desktop/test/hello.rpackage", readBytes);
		DataPack dataRead = *(DataPack*)readBytes.GetData();
		printf("Data: %d,%d,%d\n", dataRead.a, dataRead.b, dataRead.c);
		
	}

	void EditorApplication::RunEditor()
	{
		Run();
	}

	EditorApplication::~EditorApplication()
	{

	}
}