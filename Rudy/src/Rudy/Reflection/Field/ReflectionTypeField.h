#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Memory.h>
#include <Rudy/Reflection/Base/ReflectionBase.h>
#include <Rudy/Reflection/Type/ReflectionRawTypes.h>
#include <Rudy/Reflection/Base/ReflectionBindingFlags.h>
#include <cstddef>
namespace Rudy
{
	class ReflectionType;

	/// <summary>
	/// Represents the reflection of a type field
	/// </summary>
	class RUDY_API ReflectionTypeField
	{
		friend class ReflectionFieldTypeDispatcher;
	public:
		ReflectionTypeField(const String& fieldName,
			unsigned int offset, unsigned int size,
			ReflectionType* ownerType,ReflectionType* fieldType,
			int flags);
		~ReflectionTypeField() = default;

		/// <summary>
		/// Returns the offset of this field's start
		/// </summary>
		/// <returns></returns>
		unsigned int GetFieldOffset() const;

		/// <summary>
		/// Returns how many bytes this field
		/// </summary>
		/// <returns></returns>
		unsigned int GetFieldSize() const;

		/// <summary>
		/// Returns the field's name
		/// </summary>
		/// <returns></returns>
		String GetFieldName() const;

		/// <summary>
		/// Returns which type this field is
		/// </summary>
		/// <returns></returns>
		ReflectionType* GetFieldType() const;

		/// <summary>
		/// Returns which type this field belongs to
		/// </summary>
		/// <returns></returns>
		ReflectionType* GetOwnerType() const;

		/// <summary>
		/// Returns whether this type field is a static field
		/// </summary>
		/// <returns></returns>
		bool IsStatic() const;

		/// <summary>
		/// Returns whether this type field is a member field
		/// </summary>
		/// <returns></returns>
		bool IsInstance() const;

		/// <summary>
		/// Returns whether this type field is public 
		/// </summary>
		/// <returns></returns>
		bool IsPublic() const;

		/// <summary>
		/// Returns whether this type field private
		/// </summary>
		/// <returns></returns>
		bool IsPrivate() const;

		/// <summary>
		/// Returns whether this type field is protected
		/// </summary>
		/// <returns></returns>
		bool IsProtected() const;

		/// <summary>
		/// Returns whether this type field is const
		/// </summary>
		/// <returns></returns>
		bool IsConst() const;

		/// <summary>
		/// Returns whether this type field is a reference
		/// </summary>
		/// <returns></returns>
		bool IsReference() const;

		/// <summary>
		/// Returns whether this type field is a pointer
		/// </summary>
		/// <returns></returns>
		bool IsPointer() const;

		/// <summary>
		/// Returns whether this type field is a value
		/// </summary>
		/// <returns></returns>
		bool IsValue() const;

		/// <summary>
		/// Returns the binding flags of this type field
		/// </summary>
		/// <returns></returns>
		int GetBindingFlags() const;

		/// <summary>
		/// Returns a pointer to the value of the specified object's field
		/// </summary>
		/// <typeparam name="TField"></typeparam>
		/// <param name="objectPtr"></param>
		/// <returns></returns>
		template<typename TField>
		TField* GetFieldPtr(void* objectPtr) const;

		/// <summary>
		/// Returns the value of the specified object's field
		/// </summary>
		/// <typeparam name="TField"></typeparam>
		/// <param name="objectPtr"></param>
		/// <returns></returns>
		template<typename TField>
		TField GetFieldValue(void* objectPtr) const;

		/// <summary>
		/// Sets the value of the specified object's field
		/// </summary>
		/// <typeparam name="TValue"></typeparam>
		/// <param name="objectPtr"></param>
		/// <param name="value"></param>
		template<typename TValue>
		void SetFieldValue(void* objectPtr, const TValue& value) const;
	private:
		ReflectionType* m_OwnerType;
		ReflectionType* m_FieldType;
		String m_FieldName;
		unsigned int m_FieldOffset;
		unsigned int m_FieldSize;
		int m_Flags;
	};
	template<typename TField>
	inline TField* ReflectionTypeField::GetFieldPtr(void* objectPtr) const
	{
		/*
		* Get object ptr
		*/
		Byte* offsetPtr = (Byte*)objectPtr + m_FieldOffset;


		return (TField*)offsetPtr;
	}
	template<typename TField>
	inline TField ReflectionTypeField::GetFieldValue(void* objectPtr) const
	{
		/*
		* Get object ptr as byte
		*/
		Byte* bytePtr = (Byte*)objectPtr;

		/*
		* Get object offset ptr
		*/
		Byte* offsetPtr = bytePtr + m_FieldOffset;


		return (*(TField*)offsetPtr);
	}
	template<typename TValue>
	inline void ReflectionTypeField::SetFieldValue(void* objectPtr, const TValue& value) const
	{
		/*
		* Get object ptr as byte
		*/
		Byte* bytePtr = (Byte*)objectPtr;

		/*
		* Get offset
		*/
		Byte* offsetPtr = bytePtr + m_FieldOffset;

		/*
		* Get value ptr
		*/
		TValue* valuePtr = (TValue*)offsetPtr;

		/*
		* Set value
		*/
		*valuePtr = value;
	}

	/// <summary>
	/// A dispatcher class for registering fied types
	/// </summary>
	class RUDY_API ReflectionFieldTypeDispatcher
	{
	public:
		ReflectionFieldTypeDispatcher(ReflectionType* ownerType,ReflectionType* fieldType,
			const String& fieldName,
			unsigned int fieldOffset, unsigned int fieldSize,
			int flags);
		ReflectionFieldTypeDispatcher() = default;
		~ReflectionFieldTypeDispatcher() = default;
	};
	
#define GENERATE_TYPE_FIELD(type,field,fieldType,bindingFlags) Rudy::ReflectionFieldTypeDispatcher dispatcher_type_field_##type##field(type::GetStaticType(),typeof(fieldType),#field,offsetof(type,field),sizeof(type::field),bindingFlags);

}