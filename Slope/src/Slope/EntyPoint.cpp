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
#include <Rudy/Process/PlatformProcess.h>
#include <Rudy/Memory/ByteBlock.h>

#define PROJECT_ENTRY_SIZE 100
bool RenderGUI();

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
Rudy::Array<Rudy::String> g_Projects;
Rudy::String g_SlopeProjectsPath;
int main(int argumentCount, char** arguments)
{
	/*
	* Get paths
	*/
	const Rudy::String appDataPath = Rudy::PlatformPaths::GetAppDataLocalPath();
	const Rudy::String appDataRudyPath = appDataPath + "/Rudy";
	const Rudy::String slopePath = appDataRudyPath + "/Slope";
	const Rudy::String slopeProjectsPath = slopePath + "/Projects.rsettings";
	g_SlopeProjectsPath = slopeProjectsPath;

	/*
	* Validate documets rudy path
	*/
	if (!Rudy::PlatformDirectory::IsDirectoryExists(appDataRudyPath))
	{
		/*
		* Create rudy folder
		*/
		Rudy::PlatformDirectory::CreateDirectory(appDataRudyPath);
	}

	/*
	* Validate slope path
	*/
	if (!Rudy::PlatformDirectory::IsDirectoryExists(slopePath))
	{
		/*
		* Create slope path
		*/
		Rudy::PlatformDirectory::CreateDirectory(slopePath);
	}

	/*
	* Validate slope projects file
	*/
	if (!Rudy::PlatformFile::IsFileExists(slopeProjectsPath))
	{
		/*
		* Create default slope projects file
		*/
		unsigned int projectCount = 0;
		Rudy::ByteBlock projectsCountBytes(&projectCount, sizeof(projectCount));

		unsigned int copiedCount = projectsCountBytes.To<unsigned int>();

		/*
		* Write to file
		*/
		Rudy::PlatformFile::Write(slopeProjectsPath, projectsCountBytes);
	}

	/*
	* Read projects
	*/
	Rudy::ByteBlock projectCountByteBlock;
	Rudy::PlatformFile::Read(slopeProjectsPath,0,4, projectCountByteBlock);

	/*
	* Iterate projects
	*/
	const unsigned int projectCount = projectCountByteBlock.To<unsigned int>();
	unsigned int projectByteOffset = 4;
	for (unsigned int i = 0; i < projectCount; i++)
	{
		/*
		* Itereate and read projects
		*/
		Rudy::ByteBlock projectByteBlock;
		Rudy::PlatformFile::Read(slopeProjectsPath,projectByteOffset,projectByteOffset+ PROJECT_ENTRY_SIZE, projectByteBlock);

		/*
		* Get string
		*/
		Rudy::String projectPath((char*)projectByteBlock.GetBlock());

		/*
		* Increment project byte offset
		*/
		projectByteOffset += PROJECT_ENTRY_SIZE;
		g_Projects.Add(projectPath);
	}
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
		exitRequest = RenderGUI();
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
bool RenderGUI()
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
		* Render projects
		*/
		for (int i = 0; i < g_Projects.GetCursor(); i++)
		{
			/*
			* Get project path
			*/
			const Rudy::String& projectPath = g_Projects[i];

			/*
			* Render selectable
			*/
			if (Rudy::ImGuiRenderCommands::CreateSelectableItem(g_Projects[i]))
			{
				/*
				* Create editor process
				*/
				Rudy::Array<Rudy::String> cmdArguments;
				cmdArguments.Add(projectPath);
				Rudy::PlatformProcess* platformProcess = Rudy::PlatformProcess::Create(cmdArguments,
					"C:/Program Files/Rudy/Rudy/Editor.exe");
				platformProcess->Start();
				Rudy::ImGuiRenderCommands::FinalizeWindow();
				return true;
			}
		}
		Rudy::ImGuiRenderCommands::CreateHorizontalLine();

		/*
		* Render create new project button
		*/
		if (Rudy::ImGuiRenderCommands::CreateButton("Create new project"))
		{
			/*
			* Create project name&path
			*/
			const Rudy::String projectName = "Test_Project";
			const Rudy::String projectPath = Rudy::PlatformPaths::GetDocumentsPath() + "/Rudy_Projects/" + projectName +"/";

			/*
			* Register project to the global projects list
			*/
			g_Projects.Add(projectPath);

			/*
			* Validate rudy projects path
			*/
			if (!Rudy::PlatformDirectory::IsDirectoryExists(Rudy::PlatformPaths::GetDocumentsPath() + "/Rudy_Projects"))
			{
				Rudy::PlatformDirectory::CreateDirectory(Rudy::PlatformPaths::GetDocumentsPath() + "/Rudy_Projects");
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
			Rudy::Memory::MemoryCopy(projectFileContent.Name, projectName.GetSource(),projectName.GetCursor());
			projectFileContent.ProjectID = Rudy::Guid::Create();
			projectFileContent.VersionMajor = 48;
			projectFileContent.VersionMinor = 113;
			Rudy::ByteBlock projectFileContentByteBlock((Rudy::Byte*)&projectFileContent,sizeof(ProjectFileContent));
			Rudy::PlatformFile::Write(projectPath + "Project.rproject", projectFileContentByteBlock);

			/*
			* Write default project settings
			*/
			Rudy::Guid zeroGuid;
			Rudy::ByteBlock worldSettingByteBlock((Rudy::Byte*)&zeroGuid, sizeof(Rudy::Guid));
			Rudy::PlatformFile::Write(projectPath + "Settings/CurrentWorld.rsetting", worldSettingByteBlock);
			
			/*
			* Read projects file
			*/
			Rudy::ByteBlock projectFileByteBlock;
			Rudy::PlatformFile::Read(g_SlopeProjectsPath, projectFileByteBlock);

			/*
			* Create new file content byte block
			*/
			Rudy::Byte* newProjectFileByte = new Rudy::Byte[projectFileByteBlock.GetBlockSize() + 100];

			/*
			* Copy the old contents
			*/
			Rudy::Memory::MemoryCopy(newProjectFileByte, projectFileByteBlock.GetBlock(), projectFileByteBlock.GetBlockSize());

			/*
			* Alter the project number in the new projects file content
			*/
			*newProjectFileByte = g_Projects.GetCursor();

			/*
			* Append new project path bytes to new projects file content
			*/
			Rudy::Memory::MemoryCopy(
				newProjectFileByte + projectFileByteBlock.GetBlockSize(),
				projectPath.GetSource(), 100);

			/*
			* Write new projects file bytes to the disk
			*/
			Rudy::PlatformFile::Write(g_SlopeProjectsPath,
				Rudy::ByteBlock(newProjectFileByte, projectFileByteBlock.GetBlockSize() + 100));
		}
	}
	Rudy::ImGuiRenderCommands::FinalizeWindow();
	return false;
}