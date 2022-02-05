#pragma once
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Guid.h>
#include <Rudy/Reflection/Base/ReflectionBase.h>
#include <Rudy/Core/Log.h>
namespace Rudy
{
	class ReflectionTypeField;
	class ReflectionFunction;

	/// <summary>
	/// A reflection type
	/// </summary>
	class RUDY_API ReflectionType
	{
		friend class ReflectionFieldTypeDispatcher;
		friend class ReflectionMemberFunctionDispatcher;
		friend class ReflectionSubTypeDispatcher;
	public:
		ReflectionType(const String& typeName, unsigned int typeSize,bool bPrimitive);
		~ReflectionType() = default;

		/// <summary>
		/// Returns the name of this type
		/// </summary>
		/// <returns></returns>
		String GetTypeName() const;

		/// <summary>
		/// Returns a type via name
		/// </summary>
		/// <param name="fieldName"></param>
		/// <returns></returns>
		ReflectionTypeField* GetField(const String& fieldName) const;

		/// <summary>
		/// Returns a array of the fields in this type
		/// </summary>
		/// <returns></returns>
		Array<ReflectionTypeField*> GetFields() const;

		/// <summary>
		/// Returns the type id
		/// </summary>
		/// <returns></returns>
		Guid GetTypeID() const;

		/// <summary>
		/// Returns whether this type is a primitive type or not
		/// </summary>
		/// <returns></returns>
		bool IsPrimitive() const;

		/// <summary>
		/// Returns whether the given type is one of the classes which this type inherited
		/// </summary>
		/// <param name="type"></param>
		/// <returns></returns>
		bool IsSubType(ReflectionType* subType) const;

		/// <summary>
		/// Returns the type size in bytes
		/// </summary>
		/// <returns></returns>
		unsigned int GetTypeSizeInBytes() const;

		/// <summary>
		/// Returns the inherited classes
		/// </summary>
		/// <returns></returns>
		Array<ReflectionType*> GetSubTypes() const;

		/// <summary>
		/// Returns the function via name
		/// </summary>
		/// <param name="functionName"></param>
		/// <returns></returns>
		ReflectionFunction* GetFunction(const String& functionName) const;

		/// <summary>
		/// Returns all the functions
		/// </summary>
		/// <returns></returns>
		Array<ReflectionFunction*> GetFunctions() const;

		/// <summary>
		/// Generates default object
		/// </summary>
		/// <typeparam name="TObject"></typeparam>
		/// <returns></returns>
		template<typename TObject>
		TObject* GenerateDefaultObjectAs() const;

	private:
		/// <summary>
		/// An internal method used in registering type fields into this type
		/// </summary>
		/// <param name="typeField"></param>
		void RegisterTypeField(ReflectionTypeField* typeField);

		/// <summary>
		/// An internal method used in registering functions into this type
		/// </summary>
		/// <param name="function"></param>
		void RegisterFunction(ReflectionFunction* function);

		/// <summary>
		/// An internal method used in registering inherited classes
		/// </summary>
		/// <param name="inheritedType"></param>
		void RegisterSubType(ReflectionType* inheritedType);

		ReflectableObjectGenerator m_DefaultObjectGenerator;
		Array<ReflectionType*> m_SubTypes;
		Array<ReflectionTypeField*> m_Fields;
		Array<ReflectionFunction*> m_Functions;
		String m_TypeName;
		Guid m_TypeID;
		unsigned int m_TypeSize;
		bool m_bPrimitive;
	};

	template<typename TObject>
	inline TObject* ReflectionType::GenerateDefaultObjectAs() const
	{
		return (TObject*)m_DefaultObjectGenerator();
	}

	/// <summary>
	/// A dispatcher for creating new raw types
	/// </summary>
	class RUDY_API ReflectionRawTypeDispatcher
	{
	public:
		ReflectionRawTypeDispatcher(const String& typeName, unsigned int typeSize);
		~ReflectionRawTypeDispatcher() = default;

		/// <summary>
		/// Returns the raw type which is dispatched by this dispatcher
		/// </summary>
		/// <returns></returns>
		ReflectionType* GetRawType() const;
	private:
		ReflectionType* m_Type;

	};

	/// <summary>
	/// A dispatcher for registering sub types into derived types
	/// </summary>
	class RUDY_API ReflectionSubTypeDispatcher
	{
	public:
		ReflectionSubTypeDispatcher(ReflectionType* targetType,ReflectionType* subType);
		~ReflectionSubTypeDispatcher() = default;
	};

	
#define GET_RAW_NAME(name) name
#define typeof(type) GET_RAW_NAME(type)_reflection_type_acccessor_::GetOwnerType()
}