#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Reflection/Type/ReflectionType.h>
#include <typeinfo>
namespace Rudy
{
	typedef unsigned int RudyType;
	/// <summary>
	/// Base object for all reflectable objects
	/// </summary>
	/*class ReflectionType;
	class RUDY_API ReflectableObject
	{
	public:
		ReflectionType* GetType() const;
	protected:
		virtual ReflectionType* GetTypeCore() const = 0;
	};*/

	//#define GENERATE_REFLECTABLE_OBJECT(type) private:\
	//										  static Rudy::ReflectionType* s_Type;\
	//										  protected:\
	//										  virtual Rudy::ReflectionType* GetTypeCore() const override { return s_Type;}\
	//										  public:\
	//										  static Rudy::ReflectionType* GetStaticType() { return s_Type;}

	#define GENERATE_REFLECTABLE_OBJECT(type) public:\
											  virtual Rudy::RudyType GetType() const override { return typeid(type).hash_code();}\
											  static Rudy::RudyType GetStaticType() { return typeid(type).hash_code();} 
		

}