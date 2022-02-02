#pragma once
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Guid.h>
#include <Rudy/Reflection/Base/ReflectionBase.h>
#include <Rudy/Core/Log.h>
namespace Rudy
{
	class ReflectionTypeField;
	/// <summary>
	/// A reflection type
	/// </summary>
	class RUDY_API ReflectionType
	{
		friend class ReflectionFieldTypeDispatcher;
	public:
		ReflectionType(const String& typeName, unsigned int typeSize);
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
		/// Returns the type size in bytes
		/// </summary>
		/// <returns></returns>
		unsigned int GetTypeSizeInBytes() const;

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

		ReflectableObjectGenerator m_DefaultObjectGenerator;
		Array<ReflectionTypeField*> m_Fields;
		String m_TypeName;
		Guid m_TypeID;
		unsigned int m_TypeSize;
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
		ReflectionType* GetRawType() const;
	private:
		ReflectionType* m_Type;

	};
	class RUDY_API ReflectionTypeUtils
	{
	public:
		ReflectionTypeUtils() = delete;
		~ReflectionTypeUtils() = delete;

	};

	
#define GET_RAW_NAME(name) name
#define typeof(type) GET_RAW_NAME(type)_reflection_type_acccessor_::GetOwnerType()
}