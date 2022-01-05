#pragma once
#include <Bite/GUI/Module/Window/WindowLayout.h>
#include <Rudy/Reflection/Type/ReflectionType.h>

namespace Bite
{

	/// <summary>
	/// Creates anew window
	/// </summary>
	/// <typeparam name="TLayout"></typeparam>
	/// <returns></returns>
	template<typename TLayout>
	WindowLayout* CreateWindowLayout()
	{
		return new TLayout();
	}

	/// <summary>
	/// WindowLayout heap object generator function pointer
	/// </summary>
	typedef WindowLayout* (*WindowLayoutGenerator)(void);

	/// <summary>
	/// Registery for WindowLayoutGenerators
	/// </summary>
	class BITE_API WindowLayoutGeneratorRegistry
	{
	public:
		/// <summary>
		/// Returns the generator registry for current dll
		/// </summary>
		/// <returns></returns>
		static WindowLayoutGeneratorRegistry& GetCurrent();

		/// <summary>
		/// Registers anew generator
		/// </summary>
		/// <param name="generator"></param>
		void RegisterGenerator(WindowLayoutGenerator generator);

		/// <summary>
		/// Returns whether the specific generator type exists
		/// </summary>
		/// <param name="type"></param>
		/// <returns></returns>
		bool HasGenerator(Rudy::ReflectionType* type) const;


		/// <summary>
		/// Returns all the generators
		/// </summary>
		/// <returns></returns>
		Rudy::Array<WindowLayoutGenerator> GetGenerators() const;
	private:
		Rudy::Array<WindowLayoutGenerator> m_Generators;
	};

	/// <summary>
	/// Generator factory
	/// </summary>
	class BITE_API WindowLayoutGeneratorFactory
	{
	public:
		WindowLayoutGeneratorFactory(WindowLayoutGenerator generator);
	};

#define GENERATE_WINDOW_GENERATOR(def) class def;\
									   WindowLayoutGeneratorFactory window_layout_reflection_##def(&CreateWindowLayout<def>);

#define GENERATE_WINDOW(windowType,windowName) public:\
											   virtual Rudy::String GetWindowName() const override { return ##windowName;}\
											   virtual void OnLayoutSetup() override;\
											   virtual void OnLayoutRender() override;\
											   virtual void OnLayoutFinalize() override;\
											   virtual void OnVisible() override;\
											   virtual void OnInvisible() override;
}