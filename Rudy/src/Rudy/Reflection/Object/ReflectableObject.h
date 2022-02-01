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
		virtual ReflectionType* GetType() const = 0;
	};

	class RUDY_API ReflectableObjectCreator
	{
	public:
		template<typename TObject>
		static TObject* CreateReflectableObjectGenerator()
		{
			return new TObject();
		}
		ReflectableObjectCreator() = delete;
		~ReflectableObjectCreator() = delete;
	};

	/// <summary>
	/// Dispatcher for reflectable default object
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
											  static Rudy::String GetStaticClassName() { return #type;}
											  

	#define GENERATE_REFLECTABLE_TYPE(type)\
	Rudy::ReflectionType* type::s_Type = new Rudy::ReflectionType(#type,sizeof(type));\
	Rudy::ReflectableObjectDispatcher dispatcher_type_##type((Rudy::ReflectableObjectGenerator)&Rudy::ReflectableObjectCreator::CreateReflectableObjectGenerator<type>, type::GetStaticType());
}