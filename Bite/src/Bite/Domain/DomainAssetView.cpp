#include "DomainAssetView.h"
#include <Rudy/Platform/Utility/PlatformFile.h>
#include <Rudy/Memory/ByteBlock.h>
#include <Bite/Editor/Session/EditorSession.h>
#include <Rudy/Application/ApplicationSession.h>
#include <Rudy/Asset/AssetPool.h>
#include <Rudy/Asset/Asset.h>
#include <Rudy/Asset/AssetPackage.h>
#include <stdio.h>
namespace Bite
{
	DomainAssetView::DomainAssetView(const Rudy::String& absoluteAssetPath,EditorSession* ownerSession)
	{
		/*
		* Set owner session
		*/
		m_OwnerSession = ownerSession;

		/*
		* Load asset file header
		*/
		Rudy::ByteBlock defintionByteBlock;
		Rudy::PlatformFile::Read(absoluteAssetPath,0u,48u,defintionByteBlock);

		/*
		* Create defintion variables
		*/
		Rudy::AssetType assetType = defintionByteBlock.To<Rudy::AssetType>(0);
		Rudy::Guid assetID = defintionByteBlock.To<Rudy::Guid>(4);
		Rudy::String assetName((char*)((defintionByteBlock.GetBlock() + 20), 20));
		unsigned long offset = defintionByteBlock.To<unsigned long>(40);
		unsigned long size = defintionByteBlock.To<unsigned long>(44);
		Rudy::AssetDefinition definition("", assetType, assetID, assetName, offset, size);

		/*
		* Set properties
		*/
		m_Definition = definition;
		m_AbsolutePath = absoluteAssetPath;
		m_AssetName = assetName;

		/*
		* Get the asset
		*/
		m_TargetAsset = m_OwnerSession->GetApplictionSession()->GetAssetPool()->GetAsset(m_Definition.GetID());
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
		m_TargetAsset->Load(nullptr);
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
		return m_AssetName;
	}
}