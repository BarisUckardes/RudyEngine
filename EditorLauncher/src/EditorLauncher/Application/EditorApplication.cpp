#include "EditorApplication.h"
#include <Rudy/Windowing/Window.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Application/Modules/GameInputModule.h>
#include <Rudy/Application/Modules/TestModule.h>
namespace EditorLauncher
{
	EditorApplication::EditorApplication(const Rudy::String& title, unsigned int offsetX, unsigned int offsetY, unsigned int sizeX, unsigned int sizeY)
	{
		/*
		* Create new window
		*/
		Rudy::Window* newWindow = Rudy::Window::Create(title, offsetX, offsetY, sizeX, sizeY);

		/*
		* Set assing this window to the application
		*/
		SubmitWindow(newWindow);

		/*
		* Register editor application modules
		*/
		RegisterModule<Rudy::GameInputModule>();
		RegisterModule<Rudy::TestModule>();
	}

	void EditorApplication::RunEditor()
	{
		Run();
	}

	EditorApplication::~EditorApplication()
	{

	}
}