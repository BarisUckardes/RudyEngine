#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Guid.h>
#include <Bite/Project/ProjectVersion.h>
#include <Bite/Project/ProjectProperties.h>
namespace Rudy
{
	class ApplicationSession;
}
namespace Bite
{
	class DomainView;
	/// <summary>
	/// Represents a session of the editor
	/// </summary>
	class BITE_API EditorSession
	{
	public:
		EditorSession(Rudy::ApplicationSession* applicationSession);
		~EditorSession();

		/// <summary>
		/// returns the application session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::ApplicationSession* GetApplictionSession() const;

		/// <summary>
		/// Returns the domain view of this editor session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE DomainView* GetDomainView() const;

		/// <summary>
		/// Returns the project name
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::String GetProjectName() const;

		/// <summary>
		/// Returns the project properties of this session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE const ProjectProperties& GetProjectProperties() const;

		/// <summary>
		/// Sets the project for this editor session
		/// </summary>
		/// <param name="name"></param>
		/// <param name="major"></param>
		/// <param name="minor"></param>
		/// <param name="id"></param>
		void SetProject(const Rudy::String& name, unsigned int major, unsigned int minor, const Rudy::Guid& id);
	private:
		Rudy::ApplicationSession* m_ApplicationSession;
		DomainView* m_DomainView;
		ProjectProperties m_ProjectProperties;
	};


}