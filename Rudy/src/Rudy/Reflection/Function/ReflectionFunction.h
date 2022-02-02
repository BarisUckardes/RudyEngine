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
	public:
		ReflectionFunction(const String& functionName, const Array<ReflectionFunctionParameter>& parameters,ReflectionType* returnType,int flags);
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

}