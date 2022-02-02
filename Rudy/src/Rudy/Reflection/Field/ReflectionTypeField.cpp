#include "ReflectionTypeField.h"
#include <Rudy/Reflection/Type/ReflectionType.h>
namespace Rudy
{
    ReflectionTypeField::ReflectionTypeField(const String& name,
        unsigned int offset,unsigned int size,
        ReflectionType* ownerType,ReflectionType* fieldType,
        int flags)
    {
        m_FieldName = name;
        m_FieldSize = size;
        m_FieldOffset = offset;
        m_OwnerType = ownerType;
        m_FieldType = fieldType;
        m_Flags = flags;
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

    bool ReflectionTypeField::IsStatic() const
    {
        return m_Flags & ReflectionBindingFlags_Static;
    }

    bool ReflectionTypeField::IsInstance() const
    {
        return m_Flags & ReflectionBindingFlags_Instance;
    }

    bool ReflectionTypeField::IsPublic() const
    {
        return m_Flags & ReflectionBindingFlags_Public;
    }

    bool ReflectionTypeField::IsPrivate() const
    {
        return m_Flags & ReflectionBindingFlags_Private;
    }

    bool ReflectionTypeField::IsProtected() const
    {
        return (m_Flags & ReflectionBindingFlags_Protected);
    }

    bool ReflectionTypeField::IsConst() const
    {
        return (m_Flags & ReflectionBindingFlags_Const);
    }

    bool ReflectionTypeField::IsReference() const
    {
        return (m_Flags & ReflectionBindingFlags_Reference);
    }

    bool ReflectionTypeField::IsPointer() const
    {
        return (m_Flags & ReflectionBindingFlags_Pointer);
    }

    bool ReflectionTypeField::IsValue() const
    {
        return  (m_Flags & ReflectionBindingFlags_Value);
    }

    int ReflectionTypeField::GetBindingFlags() const
    {
        return m_Flags;
    }

    ReflectionFieldTypeDispatcher::ReflectionFieldTypeDispatcher(ReflectionType* ownerType,ReflectionType* fieldType,
        const String& fieldName,
        unsigned int fieldOffset,unsigned int fieldSize,
        int flags)
    {
        /*
        * Create type field
        */
        ReflectionTypeField* typeField = new ReflectionTypeField(fieldName,fieldOffset,fieldSize, ownerType, fieldType,flags);

        /*
        * Register type field to type
        */
        ownerType->RegisterTypeField(typeField);
    }

}