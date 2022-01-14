#include "EditorSession.h"
#include <stdio.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Windowing/Window.h>
namespace Bite
{
	EditorSession::EditorSession(Rudy::ApplicationSession* applicationSession)
	{
		m_ApplicationSession = applicationSession;
	}
	EditorSession::~EditorSession()
	{
		m_ApplicationSession = nullptr;
	}
	Rudy::ApplicationSession* EditorSession::GetApplictionSession() const
	{
		return m_ApplicationSession;
	}
	Rudy::String EditorSession::GetProjectName() const
	{
		return m_ProjectProperties.Name;
	}
	const ProjectProperties& EditorSession::GetProjectProperties() const
	{
		return m_ProjectProperties;
	}
	void EditorSession::SetProject(const Rudy::String& name, unsigned int major, unsigned int minor, const Rudy::Guid& id)
	{
		/*
		* Set project properties
		*/
		m_ProjectProperties.Name = name;
		m_ProjectProperties.MajorVersion = major;
		m_ProjectProperties.MinorVersion = minor;
		m_ProjectProperties.ID = id;

		/*
		* Set window title
		*/
		GetApplictionSession()->GetSessionWindow()->SetTitle(name);

		printf("Project settings adjusted as...\n");
		printf("	Name: %s\n",*name);
		printf("	Major Version: %d\n",major);
		printf("	Minor Version: %d\n",minor);
		printf("	Project ID: %s\n",*id.GetAsString());
	}
}