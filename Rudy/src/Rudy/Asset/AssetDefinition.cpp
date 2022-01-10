#include "AssetDefinition.h"
#include <string>
namespace Rudy
{
	AssetDefinition::AssetDefinition(const String& sourceFileAbsolutePath,AssetType type, const Guid& id, const String& name, unsigned long offset,unsigned long size)
	{
		m_SourceAbsolutePath = sourceFileAbsolutePath;
		m_Type = type;
		m_ID = id;
		strcpy(m_Name, *name);
		m_Offset = offset;
		m_Size = size;
	}
	String AssetDefinition::GetSourceAbsolutePath() const
	{
		return m_SourceAbsolutePath;
	}
	AssetType AssetDefinition::GetType() const
	{
		return m_Type;
	}
	Guid AssetDefinition::GetID() const
	{
		return m_ID;
	}
	String AssetDefinition::GetName() const
	{
		return m_Name;
	}
	unsigned long AssetDefinition::GetOffset() const
	{
		return m_Offset;
	}
	unsigned long AssetDefinition::GetSize() const
	{
		return m_Size;
	}
}