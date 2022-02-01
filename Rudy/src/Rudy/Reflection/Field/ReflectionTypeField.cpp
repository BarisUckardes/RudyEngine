#include "ReflectionTypeField.h"
#include <Rudy/Reflection/Type/ReflectionType.h>
namespace Rudy
{
    ReflectionTypeField::ReflectionTypeField(const String& name, unsigned int offset,unsigned int size,  ReflectionType* ownerType,ReflectionType* fieldType)
    {
        m_FieldName = name;
        m_FieldSize = size;
        m_FieldOffset = offset;
        m_OwnerType = ownerType;
        m_FieldType = fieldType;
    }
    unsigned int Rudy::ReflectionTypeField::GetFieldOffset() const
    {
        return m_FieldOffset;
    }

    unsigned int Rudy::ReflectionTypeField::GetFieldSize() const
    {
        return m_FieldSize;
    }

    String Rudy::ReflectionTypeField::GetFieldName() const
    {
        return m_FieldName;
    }

    ReflectionType* Rudy::ReflectionTypeField::GetFieldType() const
    {
        return m_FieldType;
    }

    ReflectionType* ReflectionTypeField::GetOwnerType() const
    {
        return m_OwnerType;
    }

    ReflectionTypeFieldDispatcher::ReflectionTypeFieldDispatcher(ReflectionType* ownerType,const String& fieldName,unsigned int fieldOffset,unsigned int fieldSize)
    {
        /*
        * Create type field
        */
        ReflectionTypeField* typeField = new ReflectionTypeField(fieldName,fieldOffset,fieldSize, ownerType,nullptr);

        /*
        * Register type field to type
        */
        ownerType->RegisterTypeField(typeField);

    }

}