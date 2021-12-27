#pragma once
#include <Rudy/Application/Application.h>
namespace EditorLauncher
{
	/// <summary>
	/// Editor implementation for application class
	/// </summary>
	class EditorApplication : public Rudy::Application
	{
	public:
		EditorApplication(const Rudy::String& title, unsigned int offsetX, unsigned int offsetY, unsigned int sizeX, unsigned int sizeY);
		EditorApplication() = default;
		virtual ~EditorApplication() override;

	};


}