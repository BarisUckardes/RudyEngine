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
#include <Rudy/Asset/AssetDefinition.h>
#include <Rudy/Asset/AssetPackage.h>
namespace EditorLauncher
{
	EditorApplication::EditorApplication(const Rudy::String& projectPath,const Rudy::String& title, unsigned int offsetX, unsigned int offsetY, unsigned int sizeX, unsigned int sizeY) : Rudy::Application(projectPath,Rudy::WindowCreateParameters(title,Rudy::Vector2i(offsetX,offsetY),Rudy::Vector2i(sizeX,sizeY)))
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

		/*
		* Write demo
		*/
		const unsigned int defSize = 3;
		Rudy::Array<unsigned char> defSizeBytes;
		defSizeBytes.Move((unsigned char*)&defSize, sizeof(defSize));

		Rudy::Array<Rudy::AssetDefinition> writeDefinitions;
		writeDefinitions.Add(Rudy::AssetDefinition("", Rudy::AssetType::CubeTexture, Rudy::Guid::Create(), "afsdfsd", 0, 5));
		writeDefinitions.Add(Rudy::AssetDefinition("", Rudy::AssetType::Texture2D, Rudy::Guid::Create(), "bhghr", 79, 51));
		writeDefinitions.Add(Rudy::AssetDefinition("", Rudy::AssetType::Texture3D, Rudy::Guid::Create(), "ertertc", 99, 88));

		Rudy::Array<unsigned char> defintionBytes;
		defintionBytes.Move((unsigned char*)writeDefinitions.GetData(), 48 * writeDefinitions.GetCursor());

		Rudy::Array<unsigned char> writeBytes;
		writeBytes.Add(defSizeBytes);
		writeBytes.Add(defintionBytes);
		Rudy::PlatformFile::Write("C:/Users/PC/Desktop/Test/hello.rpackage", writeBytes);

		/*
		* Read demo
		*/
		Rudy::AssetPackage* package = new Rudy::AssetPackage("C:/Users/PC/Desktop/Test/hello.rpackage");
	}

	void EditorApplication::RunEditor()
	{
		Run();
	}

	EditorApplication::~EditorApplication()
	{

	}
}