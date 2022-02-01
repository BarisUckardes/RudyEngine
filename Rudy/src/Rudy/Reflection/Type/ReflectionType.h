#pragma once
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Guid.h>
#include <Rudy/Reflection/Base/ReflectionBase.h>
namespace Rudy
{
	class ReflectionTypeField;
	/// <summary>
	/// A reflection type
	/// </summary>
	class RUDY_API ReflectionType
	{
	public:
		ReflectionType(const String& typeName,unsigned int typeSize);
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
		/// Generates default object
		/// </summary>
		/// <typeparam name="TObject"></typeparam>
		/// <returns></returns>
		template<typename TObject>
		TObject* GenerateDefaultObjectAs() const;

	private:
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

}