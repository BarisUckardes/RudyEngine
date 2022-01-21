#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Asset/AssetType.h>
#include <Rudy/Memory/String.h>
namespace Rudy
{
	class RudyObject;
	class AssetPackage;
}
namespace Bite
{
	class EditorSession;
	/// <summary>
	/// Represents an resource ownerd by the editor
	/// </summary>
	class BITE_API EditorResource
	{
	public:
		EditorResource(EditorSession* session,Rudy::AssetPackage* ownerPackage,const Rudy::AssetType type, const Rudy::String& path,const Rudy::String& name,bool bLoadAsync);
		
		/// <summary>
		/// Returns the object of the resource
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::RudyObject* GetResourceObject() const;

		/// <summary>
		/// Returns the resource asset type
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::AssetType GetAssetType() const;

		/// <summary>
		/// Returns the resource path
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::String GetAbsolutePath() const;

		/// <summary>
		/// Returns resource name
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::String GetName() const;
	private:
		~EditorResource();
		Rudy::AssetType m_AssetType;
		Rudy::RudyObject* m_TargetObject;
		Rudy::String m_AbsolutePath;
		Rudy::String m_Name;
	};

}
