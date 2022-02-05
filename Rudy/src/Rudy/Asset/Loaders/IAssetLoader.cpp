#include "IAssetLoader.h"

namespace Rudy
{
	IAssetLoader::IAssetLoader(ApplicationSession* session)
	{
		m_Session = session;
	}
	IAssetLoader::~IAssetLoader()
	{
		m_Session = nullptr;
	}
	RudyObject* IAssetLoader::Load(const ByteBlock& assetContentBytes)
	{
		return nullptr;
	}
	ApplicationSession* IAssetLoader::GetSession() const
	{
		return m_Session;
	}
}