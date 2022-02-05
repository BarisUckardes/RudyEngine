#include "DomainAssetView.h"
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Memory/ByteBlock.h>
#include <Bite/Editor/Session/EditorSession.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Asset/AssetPool.h>
#include <Rudy/Asset/Asset.h>
#include <Rudy/Asset/AssetPackage.h>
#include <stdio.h>
#include <Rudy/Core/Log.h>
namespace Bite
{
	DomainAssetView::DomainAssetView(const Rudy::String& path,EditorSession* ownerSession)
	{
		/*
		* Get the asset
		*/
		m_TargetAsset = ownerSession->GetEditorAssetPackage()->RegisterVirtualAsset(path, false);

		/*
		* Set asset view properties
		*/
		m_OwnerSession = ownerSession;
	}
	DomainAssetView::~DomainAssetView()
	{
		/*
		* Try Delete asset
		*/

		/*
		* Clear asset and owner session pointer
		*/
		m_TargetAsset = nullptr;
		m_OwnerSession = nullptr;
	}
	void DomainAssetView::TryLoadAsset(bool bLoadAsync)
	{
		/*
		* Try load asset
		*/
		m_TargetAsset->Load(m_OwnerSession->GetApplicationSession(),false);
	}
	void DomainAssetView::DeleteAsset()
	{
		/*
		* Try delete asset
		*/
		m_TargetAsset->GetOwnerPackage()->RemoveVirtualAsset(m_TargetAsset->GetID());
		m_TargetAsset = nullptr;
	}
	void DomainAssetView::RenameAsset(const Rudy::String& name)
	{

	}
	Rudy::RudyObject* DomainAssetView::GetAssetObject() const
	{
		return m_TargetAsset == nullptr ? nullptr : m_TargetAsset->GetLoadedObject();
	}
	Rudy::String DomainAssetView::GetAssetName() const
	{
		return m_TargetAsset->GetAssetHeader().Name;
	}
}