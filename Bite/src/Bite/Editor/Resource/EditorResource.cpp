#include "EditorResource.h"
#include <Rudy/Platform/Utility/PlatformPaths.h>
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Graphics/Texture/Texture2D.h>
#include <Bite/Editor/Session/EditorSession.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Asset/Asset.h>
#include <stdio.h>
namespace Bite
{
    EditorResource::EditorResource(EditorSession* session, Rudy::AssetPackage* ownerPackage,const Rudy::AssetType type, const Rudy::String& path,const Rudy::String& name, bool bLoadAsync)
    {
        /*
        * Set properties
        */
        m_AssetType = type;
        m_AbsolutePath = Rudy::PlatformPaths::GetProgramFilesPath() + "/Rudy/Bite/Resources/" + name;
        m_Name = name;

        /*
        * Create and get asset
        */
        Rudy::Asset* asset = nullptr;
        switch (m_AssetType)
        {
            case Rudy::AssetType::Undefined:
                break;
            case Rudy::AssetType::Prefab:
                break;
            case Rudy::AssetType::World:
                break;
            case Rudy::AssetType::Texture1D:
                break;
            case Rudy::AssetType::Texture2D:
            {
                asset = Rudy::Texture2D::LoadFromDisk(m_AbsolutePath, true, ownerPackage, session->GetApplictionSession()->GetDefaultGraphicsDevice());
                break;
            }
            case Rudy::AssetType::Texture3D:
                break;
            case Rudy::AssetType::CubeTexture:
                break;
            case Rudy::AssetType::Material:
                break;
            case Rudy::AssetType::Shader:
                break;
            case Rudy::AssetType::ShaderProgram:
                break;
            case Rudy::AssetType::Mesh:
                break;
            case Rudy::AssetType::Framebuffer2D:
                break;
            default:
                break;
        }

        /*
        * Load asset
        */
        asset->Load(session->GetApplictionSession());

        /*
        * Set loaded object
        */
        m_TargetObject = asset->GetLoadedObject();
    }

    Rudy::RudyObject* Bite::EditorResource::GetResourceObject() const
    {
        return m_TargetObject;
    }

    Rudy::AssetType Bite::EditorResource::GetAssetType() const
    {
        return m_AssetType;
    }

    Rudy::String Bite::EditorResource::GetAbsolutePath() const
    {
        return m_AbsolutePath;
    }

    Rudy::String Bite::EditorResource::GetName() const
    {
        return m_Name;
    }

    EditorResource::~EditorResource()
    {
        ///*
        //* Validate and destroy&delete
        //*/
        //if (m_TargetObject != nullptr)
        //{
        //    /*
        //    * Destroy
        //    */
        //    if(!m_TargetObject->IsDestroyed())
        //        m_TargetObject->Destroy();

        //    /*
        //    * Delete
        //    */
        //    delete m_TargetObject;
        //    m_TargetObject = nullptr;
        //}
    }

}