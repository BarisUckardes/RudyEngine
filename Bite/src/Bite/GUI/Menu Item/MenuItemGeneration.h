#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Memory/String.h>
#include <Bite/GUI/Menu Item/MenuItemLayout.h>
namespace Bite
{
	/// <summary>
	/// Templated generation for menu item layous
	/// </summary>
	/// <typeparam name="TLayout"></typeparam>
	/// <returns></returns>
	template<typename TLayout>
	MenuItemLayout* CreateNewMenuItemLayout()
	{
		return new TLayout();
	}

	/// <summary>
	/// MenuItemLayout heap object generator
	/// </summary>
	typedef MenuItemLayout* (*MenuItemReflectionGenerator)(void);

	/// <summary>
	/// A global per-dll defined instance of a menu item layout generator registry
	/// </summary>
	class MenuItemLayoutGeneratorRegistry
	{
	public:
		/// <summary>
		/// Returns the dll-specific registry instance
		/// </summary>
		/// <returns></returns>
		static MenuItemLayoutGeneratorRegistry& GetCurrent();
		
		MenuItemLayoutGeneratorRegistry() = default;
		~MenuItemLayoutGeneratorRegistry() = default;

		/// <summary>
		/// Registers a unique generator
		/// </summary>
		/// <param name="generator"></param>
		void RegisterNewGenerator(MenuItemReflectionGenerator generator);

		/// <summary>
		/// Returns all the generators this registry has
		/// </summary>
		/// <returns></returns>
		Rudy::Array<MenuItemReflectionGenerator> GetGenerators() const;
	private:
		Rudy::Array<MenuItemReflectionGenerator> m_Generators;
	};

	/// <summary>
	/// Utility class for generator registration
	/// </summary>
	class MenuItemReflectionGeneratorFactory
	{
	public:
		MenuItemReflectionGeneratorFactory(MenuItemReflectionGenerator generator);
	};

	/*
	* Macros
	*/
	#define GENERATE_MENU_GENERATOR(def) class def;\
	MenuItemReflectionGeneratorFactory menuitem_reflection_definition_##def(&CreateNewMenuItemLayout<def>);

	#define GENERATE_MENU_ITEM(className,itemName)  class BITE_API className : public MenuItemLayout\
													{\
													public: \
													className() = default; \
													~className() = default; \
													virtual void OnMenuItemClicked() override; \
													virtual Rudy::String GetItemName() const override { return itemName; }\
													}; \
													GENERATE_MENU_GENERATOR(className);
}