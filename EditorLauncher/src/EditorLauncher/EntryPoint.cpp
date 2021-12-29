#pragma once
#include <stdio.h>
#include <Rudy/Application/Application.h>
#include "Application/EditorApplication.h"
#include <Rudy/Platform/OS/Windows/Window/WindowsWindow.h>
#include <Rudy/Events/Keyboard/KeyboardKeyDownEvent.h>
int main(int argumentCount, char** arguments)
{
	/*
	* Create editor application
	*/
	EditorLauncher::EditorApplication* application = new EditorLauncher::EditorApplication("Random title name",100,100,1280,720);

	/*
	* Run application
	*/
	application->Run();



	return 0;
}