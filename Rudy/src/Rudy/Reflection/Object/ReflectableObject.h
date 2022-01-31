#pragma once
#include <Rudy/Core/Symbols.h>
namespace Rudy
{
	//typedef unsigned int RudyType;
	/// <summary>
	/// Base object for all reflectable objects
	/// </summary>
	class ReflectionType;
	class RUDY_API ReflectableObject
	{
	public:
		virtual ReflectionType* GetType() const = 0;
	};

	typedef ReflectableObject* (*DefaultReflectableObjectGenerator)(void);

	/// <summary>
	/// Dispatcher for reflectable default object
	/// </summary>
	class RUDY_API DefaultReflectableObjectDispatcher
	{
	public:
		DefaultReflectableObjectDispatcher(DefaultReflectableObjectGenerator generator, ReflectionType* ownerType);
		~DefaultReflectableObjectDispatcher() = default;
	};

	#define GENERATE_REFLECTABLE_OBJECT(type) private:\
											  static Rudy::ReflectionType* s_Type;\
											  protected:\
											  virtual Rudy::ReflectionType* GetType() const override { return s_Type;}\
											  public:\
											  static Rudy::ReflectionType* GetStaticType() { return s_Type;}\
											  static Rudy::String GetStaticClassName() { return #type;}
											  

	#define GENERATE_REFLECTABLE_TYPE(type)\
	Rudy::ReflectionType* type::s_Type = new Rudy::ReflectionType(#type,sizeof(type));\
	Rudy::DefaultReflectableObjectDispatcher(s_Type,...);

}