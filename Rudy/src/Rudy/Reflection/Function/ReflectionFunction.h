#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Reflection/Function/ReflectionFunctionParameter.h>
namespace Rudy
{
	class ReflectionType;

	/// <summary>
	/// Represents the reflection of a function
	/// </summary>
	class RUDY_API ReflectionFunction
	{
		friend class ReflectionMemberFunctionParameterDispatcher;
	public:
		ReflectionFunction(const String& functionName,ReflectionType* returnType, const Array<ReflectionFunctionParameter>& parameters,int flags);
		ReflectionFunction();

		/// <summary>
		/// Returns whether this funtion is public or not
		/// </summary>
		/// <returns></returns>
		bool IsPublic() const;

		/// <summary>
		/// Returns whether this function is private or not
		/// </summary>
		/// <returns></returns>
		bool IsPrivate() const;

		/// <summary>
		/// Returns whether this function is protected or not
		/// </summary>
		/// <returns></returns>
		bool IsProtected() const;

		/// <summary>
		/// Returns whether this function is static or not
		/// </summary>
		/// <returns></returns>
		bool IsStatic() const;

		/// <summary>
		/// Returns whether this function is a member function or not
		/// </summary>
		/// <returns></returns>
		bool IsInstance() const;

		/// <summary>
		/// Returns whether this function is a virtual or not
		/// </summary>
		/// <returns></returns>
		bool IsVirtual() const;

		/// <summary>
		/// Returns whether this function is a pure virtual or not
		/// </summary>
		/// <returns></returns>
		bool IsPureVirtual() const;

		/// <summary>
		/// Returns whether this function is a const function or not
		/// </summary>
		/// <returns></returns>
		bool IsConstFunction() const;

		/// <summary>
		/// Returns the name of the function
		/// </summary>
		/// <returns></returns>
		String GetName() const;

		/// <summary>
		/// Returns the parameter meta data list of this function's parameters
		/// </summary>
		/// <returns></returns>
		Array<ReflectionFunctionParameter> GetParameters() const;

		/// <summary>
		/// Returns the return type of this function
		/// </summary>
		/// <returns></returns>
		ReflectionType* GetReturnType() const;

		/// <summary>
		/// Calls the function with the specified templates and parameters
		/// </summary>
		/// <typeparam name="TReturn"></typeparam>
		/// <typeparam name="...TArgs"></typeparam>
		/// <param name="targetObject"></param>
		/// <param name="...args"></param>
		/// <returns></returns>
		template<typename TReturn,typename ...TArgs>
		TReturn Call(void* targetObject, TArgs... args);
	private:
		/// <summary>
		/// Internal setter for registering parameters into this function
		/// </summary>
		/// <param name="parameter"></param>
		void RegisterParameter(const ReflectionFunctionParameter& parameter);

		Array<ReflectionFunctionParameter> m_Parameters;
		ReflectionType* m_ReturnType;
		String m_Name;
		int m_Flags;
	};


	template<typename TReturn, typename ...TArgs>
	inline TReturn ReflectionFunction::Call(void* targetObject, TArgs ...args)
	{
		return TReturn();
	}

	/// <summary>
	/// Dispatches a reflection member function register call
	/// </summary>
	class RUDY_API ReflectionMemberFunctionDispatcher
	{
	public:
		ReflectionMemberFunctionDispatcher(ReflectionType* memberType,ReflectionType* returnType, const String& functionName,const Array<ReflectionFunctionParameter>& parameters,int flags);

		/// <summary>
		/// Returns the function which created and registered within this dispatcher
		/// </summary>
		/// <returns></returns>
		ReflectionFunction* GetFunction() const;
	private:
		ReflectionFunction* m_Function;
	};

	/// <summary>
	/// Dispatches a reflection member function parameter register call
	/// </summary>
	class RUDY_API ReflectionMemberFunctionParameterDispatcher
	{
	public:
		ReflectionMemberFunctionParameterDispatcher(ReflectionFunction* ownerFunction, ReflectionType* parameterType, const String& parameterName);
		
	};
#define GENERATE_MEMBER_FUNCTION_PARAMETER(memberType,function,parameterType,parameterName) Rudy::ReflectionMemberFunctionParameterDispatcher GET_RAW_NAME(parameterName)GET_RAW_NAME(function)_reflection_member_function_parameter_dispatcher(GET_RAW_NAME(memberType)GET_RAW_NAME(function)_reflection_member_function_dispatcher.GetFunction(),typeof(parameterType),#parameterName);
#define GENERATE_MEMBER_FUNCTION(memberType,function,returnType,flags) Rudy::ReflectionMemberFunctionDispatcher GET_RAW_NAME(memberType)GET_RAW_NAME(function)_reflection_member_function_dispatcher(typeof(memberType),typeof(returnType),#function,Rudy::Array<Rudy::ReflectionFunctionParameter>(),flags);

}