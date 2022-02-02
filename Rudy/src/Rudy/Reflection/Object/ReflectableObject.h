#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Reflection/Base/ReflectionBase.h>
#include <Rudy/Reflection/Type/ReflectionType.h>
namespace Rudy
{
	//typedef unsigned int RudyType;
	/// <summary>
	/// Base object for all reflectable objects
	/// </summary>
	class RUDY_API ReflectableObject
	{
	public:
		/// <summary>
		/// Returns the type of this object
		/// </summary>
		/// <returns></returns>
		virtual ReflectionType* GetType() const = 0;
	};

	/// <summary>
	/// A class for creating reflectable object default contstructor function pointer
	/// </summary>
	class RUDY_API ReflectableObjectCreator
	{
	public:
		/// <summary>
		/// Creates a function pointer to the default constructor of a reflectable object
		/// </summary>
		/// <typeparam name="TObject"></typeparam>
		/// <returns></returns>
		template<typename TObject>
		static TObject* CreateReflectableObjectGenerator()
		{
			return new TObject();
		}
		ReflectableObjectCreator() = delete;
		~ReflectableObjectCreator() = delete;
	};

	/// <summary>
	/// Dispatcher class for registering the reflectable objects
	/// </summary>
	class RUDY_API ReflectableObjectDispatcher
	{
	public:
		ReflectableObjectDispatcher(ReflectableObjectGenerator generator, ReflectionType* ownerType);
		~ReflectableObjectDispatcher() = default;
	};

	#define GENERATE_REFLECTABLE_OBJECT(type) private:\
											  static Rudy::ReflectionType* s_Type;\
											  protected:\
											  public:\
											  virtual Rudy::ReflectionType* GetType() const override { return s_Type; }\
											  static Rudy::ReflectionType* GetStaticType() { return s_Type;}\
												
											  

	#define GENERATE_REFLECTABLE_TYPE(type)\
	Rudy::ReflectionType* type::s_Type = new Rudy::ReflectionType(#type,sizeof(type),false);\

	#define GENERATE_REFLECTION_ACCESSOR(type) class GET_RAW_NAME(type)_reflection_type_acccessor_\
	{\
	public:\
		static Rudy::ReflectionType* GetOwnerType() { return type::GetStaticType(); }\
	}
}