#include "ReflectionTypeField.h"

namespace Rudy
{
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

}