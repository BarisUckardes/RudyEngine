#include "EditorApplication.h"
#include <Rudy/Windowing/Window.h>
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
	}

	EditorApplication::~EditorApplication()
	{

	}
}