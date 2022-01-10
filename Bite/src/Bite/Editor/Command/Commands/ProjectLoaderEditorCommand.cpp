#include "ProjectLoaderEditorCommand.h"
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Bite/Project/ProjectFileContent.h>
namespace Bite
{
    ProjectLoaderEditorCommand::ProjectLoaderEditorCommand(const Rudy::String& projectFolder)
    {
        m_ProjectFolder = projectFolder;
    }
    void ProjectLoaderEditorCommand::OnInitialize()
    {
        /*
        * Load project name-version etc
        */
        Rudy::Array<unsigned char> projectFileBytes;
        Rudy::PlatformFile::Read(m_ProjectFolder,projectFileBytes);

        /*
        * Create project file content
        */
        ProjectFileContent content;
        content = *(ProjectFileContent*)projectFileBytes.GetData();

        /*
        * Set session project file settings
        */
    }
    void ProjectLoaderEditorCommand::OnFinalize()
    {
        /*
        * Save last project state
        */
        Rudy::Array<unsigned char> projectFileBytes;
        Rudy::PlatformFile::Write(m_ProjectFolder, projectFileBytes);
    }
}