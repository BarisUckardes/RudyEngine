#include "ReflectionFunction.h"

namespace Rudy
{
    Rudy::ReflectionFunction::ReflectionFunction(const String& functionName, const Array<ReflectionFunctionParameter>& parameters, ReflectionType* returnType, int flags)
    {
    }

    Rudy::ReflectionFunction::ReflectionFunction()
    {
    }

    bool Rudy::ReflectionFunction::IsPublic() const
    {
        return false;
    }

    bool Rudy::ReflectionFunction::IsPrivate() const
    {
        return false;
    }

    bool Rudy::ReflectionFunction::IsProtected() const
    {
        return false;
    }

    bool Rudy::ReflectionFunction::IsStatic() const
    {
        return false;
    }

    bool Rudy::ReflectionFunction::IsInstance() const
    {
        return false;
    }

    bool Rudy::ReflectionFunction::IsVirtual() const
    {
        return false;
    }

    bool Rudy::ReflectionFunction::IsPureVirtual() const
    {
        return false;
    }

    bool Rudy::ReflectionFunction::IsConstFunction() const
    {
        return false;
    }

    Array<ReflectionFunctionParameter> Rudy::ReflectionFunction::GetParameters() const
    {
        return Array<ReflectionFunctionParameter>();
    }

    ReflectionType* Rudy::ReflectionFunction::GetReturnType() const
    {
        return nullptr;
    }

}