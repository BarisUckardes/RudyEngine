#pragma once
#include <stdio.h>
#include <Rudy/Application/Application.h>
#include "Application/EditorApplication.h"
#include <Rudy/Platform/OS/Windows/Window/WindowsWindow.h>
#include <Rudy/Events/Keyboard/KeyboardKeyDownEvent.h>
int main(int argumentCount, char** arguments)
{
	/*
	* Get editor executable path
	*/
	const Rudy::String executablePath(arguments[0]);

	/*
	* Get project path
	*/
	const Rudy::String projectPath(arguments[0]);

	/*
	* Create editor application
	*/
	EditorLauncher::EditorApplication* application = new EditorLauncher::EditorApplication(projectPath,"Random title name",100,100,1280,720);

	/*
	* Run application
	*/
	application->RunEditor();



	return 0;
}