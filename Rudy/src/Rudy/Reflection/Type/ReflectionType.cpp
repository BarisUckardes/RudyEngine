#include "ReflectionType.h"
#include <Rudy/Reflection/Field/ReflectionTypeField.h>
#include <Rudy/Reflection/Function/ReflectionFunction.h>
#include <stdio.h>
namespace Rudy
{
	ReflectionType::ReflectionType(const String& typeName, unsigned int typeSize,Array<ReflectionType*> inheritedClasses,bool bPrimitive)
	{
		/*
		* Set reflection properties
		*/
		m_TypeName = typeName;
		m_TypeSize = typeSize;
		m_bPrimitive = bPrimitive;
		m_InheritedClasses = inheritedClasses;

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
	Array<ReflectionType*> ReflectionType::GetInheritedClasses() const
	{
		return m_InheritedClasses;
	}
	ReflectionFunction* ReflectionType::GetFunction(const String& functionName) const
	{
		/*
		* Iterate and search for name match
		*/
		for (unsigned int i = 0; i < m_Functions.GetCursor(); i++)
		{
			/*
			* Get Field type
			*/
			ReflectionFunction* function = m_Functions[i];

			/*
			* Validate
			*/
			if (function->GetName() == functionName)
			{
				LOG("Function[%s] found in [%s]", *function->GetName(), *m_TypeName);
				return function;
			}
				
		}
		LOG("Function NOT FOUNDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
		return nullptr;
	}
	Array<ReflectionFunction*> ReflectionType::GetFunctions() const
	{
		return m_Functions;
	}
	void ReflectionType::RegisterTypeField(ReflectionTypeField* typeField)
	{
		m_Fields.Add(typeField);
	}
	void ReflectionType::RegisterFunction(ReflectionFunction* function)
	{
		m_Functions.Add(function);
	}
	ReflectionRawTypeDispatcher::ReflectionRawTypeDispatcher(const String& typeName, unsigned int typeSize)
	{
		/*
		* Create new type
		*/
		ReflectionType* rawType = new ReflectionType(typeName, typeSize, {}, true);
		m_Type = rawType;

		/*
		* Register raw type to assembly
		*/
	}

	ReflectionType* ReflectionRawTypeDispatcher::GetRawType() const
	{
		return m_Type;
	}


}