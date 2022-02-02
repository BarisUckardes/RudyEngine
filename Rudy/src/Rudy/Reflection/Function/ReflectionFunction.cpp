#include "ReflectionFunction.h"
#include <Rudy/Reflection/Type/ReflectionType.h>
namespace Rudy
{
    Rudy::ReflectionFunction::ReflectionFunction(const String& functionName, ReflectionType* returnType, const Array<ReflectionFunctionParameter>& parameters, int flags)
    {
        m_Name = functionName;
        m_Parameters = parameters;
        m_ReturnType = returnType;
        m_Flags = flags;
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

    String ReflectionFunction::GetName() const
    {
        return m_Name;
    }

    Array<ReflectionFunctionParameter> Rudy::ReflectionFunction::GetParameters() const
    {
        return m_Parameters;
    }

    ReflectionType* Rudy::ReflectionFunction::GetReturnType() const
    {
        return nullptr;
    }
    void ReflectionFunction::RegisterParameter(const ReflectionFunctionParameter& parameter)
    {
        m_Parameters.Add(parameter);
    }

    ReflectionMemberFunctionDispatcher::ReflectionMemberFunctionDispatcher(ReflectionType* memberType,ReflectionType* returnType,
        const String& functionName,
        const Array<ReflectionFunctionParameter>& parameters,
        int flags)
    {
        /*
        * Create new function
        */
        ReflectionFunction* function = new ReflectionFunction(functionName, returnType, parameters, 0);
        m_Function = function;

        /*
        * Register function
        */
        memberType->RegisterFunction(function);
        
    }
    ReflectionFunction* ReflectionMemberFunctionDispatcher::GetFunction() const
    {
        return m_Function;
    }
    ReflectionMemberFunctionParameterDispatcher::ReflectionMemberFunctionParameterDispatcher(ReflectionFunction* ownerFunction, ReflectionType* parameterType,const String& parameterName)
    {
        /*
        * Create function parameter
        */
        ReflectionFunctionParameter parameter(parameterName, parameterType);

        /*
        * Register function parameter
        */
        ownerFunction->RegisterParameter(parameter);

    }

}