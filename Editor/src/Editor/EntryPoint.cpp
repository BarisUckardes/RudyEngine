#pragma once
#include <stdio.h>
#include <Rudy/Application/Application.h>
#include "Application/EditorApplication.h"
#include <Rudy/Platform/Implementation/OS/Windows/Window/WindowsWindow.h>
#include <Rudy/Application/Events/Keyboard/KeyboardKeyDownEvent.h>
#include "Test/TestClass.h"
#include <Rudy/Core/Log.h>
#include <Rudy/World/World.h>
//int main(int argumentCount, char** arguments)
//{
//	///*
//	//* Get editor executable path
//	//*/
//	//const Rudy::String executablePath(arguments[0]);
//	// 
//	///*
//	//* Get project path
//	//*/
//	//const Rudy::String projectFolderPath(arguments[1]);
//
//	///*
//	//* Create editor application
//	//*/
//	//EditorLauncher::EditorApplication* application = new EditorLauncher::EditorApplication(projectFolderPath,"Random title name",100,100,1280,720);
//
//	///*
//	//* Run application
//	//*/
//	//application->RunEditor();
//	Rudy::PlatformWindow* window = new Rudy::PlatformWindow("Title", 0, 0, 1280, 720, GetModuleHandle(0));
//	while(1) {}
//
//	return 0;
//}
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Rudy::PlatformWindow* window = new Rudy::PlatformWindow("Title", 0, 0, 1280, 720, hInstance);
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}