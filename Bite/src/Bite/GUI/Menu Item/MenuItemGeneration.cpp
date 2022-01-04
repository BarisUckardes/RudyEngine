#include "MenuItemGeneration.h"

namespace Bite
{
	MenuItemLayoutGeneratorRegistry& MenuItemLayoutGeneratorRegistry::GetCurrent()
	{
		static MenuItemLayoutGeneratorRegistry instance;
		return instance;
	}

	void MenuItemLayoutGeneratorRegistry::RegisterNewGenerator(MenuItemReflectionGenerator generator)
	{
		/*
		* Register reflection
		*/
		m_Generators.Add(generator);
	}

	Rudy::Array<MenuItemReflectionGenerator> MenuItemLayoutGeneratorRegistry::GetGenerators() const
	{
		return m_Generators;
	}

	MenuItemReflectionGeneratorFactory::MenuItemReflectionGeneratorFactory(MenuItemReflectionGenerator generator)
	{
		MenuItemLayoutGeneratorRegistry::GetCurrent().RegisterNewGenerator(generator);
	}
}