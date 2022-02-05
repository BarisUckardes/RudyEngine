#include "IAssetWriter.h"

namespace Bite
{
	IAssetWriter::IAssetWriter(Rudy::ApplicationSession* session)
	{
		m_Session = session;
	}
	IAssetWriter::~IAssetWriter()
	{
		m_Session = nullptr;
	}
	Rudy::ApplicationSession* IAssetWriter::GetSession() const
	{
		return m_Session;
	}
}