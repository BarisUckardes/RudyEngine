#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Memory.h>
namespace Rudy
{
	class ReflectionType;
	class RUDY_API ReflectionTypeField
	{
	public:
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
		ReflectionType* m_FieldType;
		String m_FieldName;
		unsigned int m_FieldOffset;
		unsigned int m_FieldSize;
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
}