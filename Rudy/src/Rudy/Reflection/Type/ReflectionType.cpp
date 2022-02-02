#include "ReflectionType.h"
#include <Rudy/Reflection/Field/ReflectionTypeField.h>
#include <stdio.h>
namespace Rudy
{
	ReflectionType::ReflectionType(const String& typeName, unsigned int typeSize,bool bPrimitive)
	{
		/*
		* Set reflection properties
		*/
		m_TypeName = typeName;
		m_TypeSize = typeSize;
		m_bPrimitive = bPrimitive;

		/*
		* Register this reflection into its assembly
		*/

		//printf("New reflectable object: %s\n", *typeName);
	}

	String ReflectionType::GetTypeName() const
	{
		return m_TypeName;
	}
	Guid ReflectionType::GetTypeID() const
	{
		return m_TypeID;
	}
	bool ReflectionType::IsPrimitive() const
	{
		return m_bPrimitive;
	}
	ReflectionTypeField* ReflectionType::GetField(const String& fieldName) const
	{
		/*
		* Iterate and search for name match
		*/
		for (unsigned int i = 0; i < m_Fields.GetCursor(); i++)
		{
			/*
			* Get Field type
			*/
			ReflectionTypeField* typeField = m_Fields[i];

			/*
			* Validate
			*/
			if (typeField->GetFieldName() == fieldName)
				return typeField;
		}

		return nullptr;
	}
	Array<ReflectionTypeField*> ReflectionType::GetFields() const
	{
		return m_Fields;
	}
	unsigned int ReflectionType::GetTypeSizeInBytes() const
	{
		return m_TypeSize;
	}
	void ReflectionType::RegisterTypeField(ReflectionTypeField* typeField)
	{
		m_Fields.Add(typeField);
	}
	ReflectionRawTypeDispatcher::ReflectionRawTypeDispatcher(const String& typeName, unsigned int typeSize)
	{
		/*
		* Create new type
		*/
		ReflectionType* rawType = new ReflectionType(typeName,typeSize,true);
		m_Type = rawType;

		/*
		* Register raw type to assembly
		*/
		LOG("Raw type registered %s", *m_Type->GetTypeName());
	}

	ReflectionType* ReflectionRawTypeDispatcher::GetRawType() const
	{
		return m_Type;
	}


}