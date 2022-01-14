#include "ProjectLoaderEditorCommand.h"
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Bite/Project/ProjectFileContent.h>
#include <Bite/Editor/Session/EditorSession.h>
#include <Rudy/Memory/ByteBlock.h>
#include <stdio.h>
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
        Rudy::ByteBlock projectFileByteBlock;
        Rudy::PlatformFile::Read(m_ProjectFolder + "/Project.rproject", projectFileByteBlock);

        /*
        * Create project file content
        */
        ProjectFileContent content;
        content = projectFileByteBlock.To<ProjectFileContent>();

        /*
        * Set session project file settings
        */
        GetOwnerSession()->SetProject(content.Name, content.VersionMajor, content.VersionMinor, content.ProjectID);
    }
    void ProjectLoaderEditorCommand::OnFinalize()
    {
        /*
        * Get last project state
        */

        /*
        * Save last project state
        */
        Rudy::ByteBlock projectFileByteBlock;
        Rudy::PlatformFile::Write(m_ProjectFolder, projectFileByteBlock);
    }
}