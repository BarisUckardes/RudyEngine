#include <Rudy/Windowing/Window.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/ImGui/ImGuiRenderer.h>
#include <Rudy/Graphics/Command/CommandBuffer.h>
#include <Rudy/Mathematics/ColorRgba.h>
#include <Rudy/ImGui/Commands/ImGuiLayoutCommands.h>
#include <Rudy/ImGui/Commands/ImGuiRenderCommands.h>
#include <Rudy/Platform/Utility/PlatformDirectory.h>
#include <Rudy/Platform/Utility/PlatformPaths.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Memory/Guid.h>
#include <string>
void RenderGUI();

struct ProjectFileContent
{
	/// <summary>
	/// The name of the project.(max 20 chars)
	/// </summary>
	char Name[20];

	/// <summary>
	/// The major version
	/// </summary>
	unsigned int VersionMajor;

	/// <summary>
	/// The minor version
	/// </summary>
	unsigned int VersionMinor;

	/// <summary>
	/// The unique id of this project
	/// </summary>
	Rudy::Guid ProjectID;
};
int main(int argumentCount, char** arguments)
{
	/*
	* Create window
	*/
	Rudy::Window* window = Rudy::Window::Create("Slope", 100, 100, 1280, 720);

	/*
	* Create renderer
	*/
	Rudy::ImGuiRenderer* renderer = new Rudy::ImGuiRenderer(Rudy::Vector2i(1280, 720), window->GetGraphicsDevice()->GetApiType());

	/*
	* Register event delegate
	*/
	Rudy::Delegate<void, Rudy::Event*> rendererEvent = Rudy::Delegate<void, Rudy::Event*>(RUDY_BIND_TARGET_EVENT(renderer, Rudy::ImGuiRenderer::OnEventReceived));
	window->RegisterCallBack(rendererEvent);

	/*
	* Slope loop
	*/
	bool exitRequest = false;
	while (!exitRequest)
	{
		/*
		* Clear color
		*/
		Rudy::CommandBuffer* cmdBuffer = window->GetGraphicsDevice()->CreateCommandBuffer();
		cmdBuffer->StartRecording();
		cmdBuffer->ClearColor(Rudy::ColorRgba(0, 0, 0, 1.0f));
		cmdBuffer->FinalizeRecording();
		cmdBuffer->Execute();
		delete cmdBuffer;

		/*
		* Update window
		*/
		window->PollBufferedEvents();

		/*
		* Render gui
		*/
		renderer->Begin();
		RenderGUI();
		renderer->End();

		/*
		* Swapbuffers
		*/
		window->GetGraphicsDevice()->Swapbuffers();

		/*
		* Validate exit
		*/
		if (window->HasCloseRequest())
			exitRequest = true;

	}
	return 0;
}
void RenderGUI()
{
	/*
	* Render window
	*/
	Rudy::ImGuiLayoutCommands::SetNextWindowSize(Rudy::ImGuiLayoutCommands::GetViewportSize());
	Rudy::ImGuiLayoutCommands::SetNextWindowPosition(Rudy::ImGuiLayoutCommands::GetViewportPosition());
	if (Rudy::ImGuiRenderCommands::BeginWindow("Main Window",
		Rudy::GUIWindowFlags::NoTitleBar |
		Rudy::GUIWindowFlags::NoCollapse |
		Rudy::GUIWindowFlags::NoResize   |
		Rudy::GUIWindowFlags::NoMove     |
		Rudy::GUIWindowFlags::NoBringToFrontOnFocus |
		Rudy::GUIWindowFlags::NoNavFocus
	))
	{
		Rudy::ImGuiLayoutCommands::SetCurrentWindowFontScale(5.0f);

		/*
		* Render projects text
		*/
		Rudy::ImGuiRenderCommands::CreateText("Projects:");
		Rudy::ImGuiRenderCommands::CreateHorizontalLine();


		/*
		* Render selectable projects
		*/
		Rudy::ImGuiRenderCommands::CreateSelectableItem("MySelectable");
		Rudy::ImGuiRenderCommands::CreateSelectableItem("MySelectable2");
		Rudy::ImGuiRenderCommands::CreateSelectableItem("MySelectable3");

		Rudy::ImGuiRenderCommands::CreateHorizontalLine();

		/*
		* Render create new project button
		*/
		if (Rudy::ImGuiRenderCommands::CreateButton("Create new project"))
		{
			const Rudy::String projectName = "Test Project";

			const Rudy::String projectPath = Rudy::PlatformPaths::GetDocumentsPath() + "/Rudy Projects/" + projectName +"/";
			/*
			* Validate rudy projects path
			*/
			if (!Rudy::PlatformDirectory::IsDirectoryExists(Rudy::PlatformPaths::GetDocumentsPath() + "/Rudy Projects"))
			{
				Rudy::PlatformDirectory::CreateDirectory(Rudy::PlatformPaths::GetDocumentsPath() + "/Rudy Projects");
			}

			/*
			* Create project folders
			*/
			Rudy::PlatformDirectory::CreateDirectory(projectPath);
			Rudy::PlatformDirectory::CreateDirectory(projectPath + "Domain/");
			Rudy::PlatformDirectory::CreateDirectory(projectPath + "Code/");
			Rudy::PlatformDirectory::CreateDirectory(projectPath + "Settings/");

			/*
			* Write project file
			*/
			ProjectFileContent projectFileContent;
			strcpy_s(projectFileContent.Name, projectName.GetSource());
			projectFileContent.ProjectID = Rudy::Guid::Create();
			projectFileContent.VersionMajor = 48;
			projectFileContent.VersionMinor = 113;

			Rudy::Array<unsigned char> projectFileContentBytes;
			projectFileContentBytes.Copy((unsigned char*)&projectFileContent, sizeof(projectFileContent));
			Rudy::PlatformFile::Write(projectPath + "Project.rproject", projectFileContentBytes);

			/*
			* Write default project settings
			*/
			Rudy::Guid zeroGuid;
			Rudy::Array<unsigned char> worldSettingBytes;
			worldSettingBytes.Copy((unsigned char*)&zeroGuid, sizeof(Rudy::Guid));
			Rudy::PlatformFile::Write(projectPath + "Settings/CurrentWorld.rsetting", worldSettingBytes);
		}
	}
	Rudy::ImGuiRenderCommands::FinalizeWindow();
}