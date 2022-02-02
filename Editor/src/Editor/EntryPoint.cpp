#pragma once
#include <stdio.h>
#include <Rudy/Application/Application.h>
#include "Application/EditorApplication.h"
#include <Rudy/Platform/Implementation/OS/Windows/Window/WindowsWindow.h>
#include <Rudy/Application/Events/Keyboard/KeyboardKeyDownEvent.h>
#include "Test/TestClass.h"
#include <Rudy/Core/Log.h>
#include <Rudy/World/World.h>

int main(int argumentCount, char** arguments)
{
	Rudy::ReflectionType* type = typeof(uint);
	
	LOG("GETTTTTTTTTTTT Type name: %s", *type->GetTypeName());

	/*
	* Get editor executable path
	*/
	const Rudy::String executablePath(arguments[0]);
	 
	/*
	* Get project path
	*/
	const Rudy::String projectFolderPath(arguments[1]);

	printf("Executable path: %s, Project folder path: %s\n", *executablePath, *projectFolderPath);

	/*
	* Create editor application
	*/
	EditorLauncher::EditorApplication* application = new EditorLauncher::EditorApplication(projectFolderPath,"Random title name",100,100,1280,720);

	/*
	* Run application
	*/
	application->RunEditor();

	return 0;
}