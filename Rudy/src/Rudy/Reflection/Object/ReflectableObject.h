#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Base object for all reflectable objects
	/// </summary>
	class ReflectionType;
	class RUDY_API ReflectableObject
	{
	public:
		ReflectionType* GetType() const;
	protected:
		virtual ReflectionType* GetTypeCore() const = 0;
	};

	#define GENERATE_REFLECTABLE_OBJECT(type) private:\
											  inline static Rudy::ReflectionType* s_Type = nullptr;\
											  protected:\
											  virtual Rudy::ReflectionType* GetTypeCore() const override { return s_Type;}\
											  public:\
											  static Rudy::ReflectionType* GetStaticType() { return s_Type;}
		

}