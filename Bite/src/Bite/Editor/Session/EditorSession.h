#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Guid.h>
#include <Bite/Project/ProjectVersion.h>
#include <Bite/Project/ProjectProperties.h>
#include <Rudy/Asset/AssetType.h>
namespace Rudy
{
	class ApplicationSession;
	class AssetObject;
	class AssetPackage;
}
namespace Bite
{
	class DomainView;
	class EditorResource;
	class GUIPainter;
	/// <summary>
	/// Represents a session of the editor
	/// </summary>
	class BITE_API EditorSession
	{
	public:
		EditorSession(Rudy::ApplicationSession* applicationSession,GUIPainter* painter);
		~EditorSession();

		/// <summary>
		/// returns the application session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::ApplicationSession* GetApplicationSession() const;

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
		/// Returns the editor source by name and the type
		/// </summary>
		/// <param name="type"></param>
		/// <param name="name"></param>
		/// <returns></returns>
		FORCEINLINE Rudy::AssetObject* GetEditorResource(Rudy::AssetType type, const Rudy::String& name);

		/// <summary>
		/// Returns the session gui painter
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GUIPainter* GetSessionPainter() const;

		/// <summary>
		/// Returns the virtual asset package of the editor
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::AssetPackage* GetEditorAssetPackage() const;

		/// <summary>
		/// Sets the project for this editor session
		/// </summary>
		/// <param name="name"></param>
		/// <param name="major"></param>
		/// <param name="minor"></param>
		/// <param name="id"></param>
		void SetProject(const Rudy::String& name, unsigned int major, unsigned int minor, const Rudy::Guid& id);

		/// <summary>
		/// Sets the editor resources for this editor session
		/// </summary>
		/// <param name="resources"></param>
		void SetEditorResources(const Rudy::Array<EditorResource*>& resources);
	private:
		Rudy::Array<EditorResource*> m_EditorResources;
		Rudy::ApplicationSession* m_ApplicationSession;
		Rudy::AssetPackage* m_AssetPackage;
		DomainView* m_DomainView;
		GUIPainter* m_Painter;
		ProjectProperties m_ProjectProperties;
	};


}