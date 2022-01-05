#include "WindowLayoutGeneration.h"
#include <xstring>

namespace Bite
{
	WindowLayoutGeneratorRegistry& Bite::WindowLayoutGeneratorRegistry::GetCurrent()
	{
		static WindowLayoutGeneratorRegistry registry;
		return registry;
	}

	void WindowLayoutGeneratorRegistry::RegisterGenerator(WindowLayoutGenerator generator)
	{

		/*
		* Check if already has this generator
		*/
		WindowLayout* layout = generator();
		printf("New gui window %s\n", *layout->GetWindowName());
		if (HasGenerator(layout->GetType()))
		{
			delete layout;
			return;
		}
		delete layout;

		/*
		* Register generator
		*/
		m_Generators.Add(generator);
	}

	bool WindowLayoutGeneratorRegistry::HasGenerator(Rudy::ReflectionType* type) const
	{
		/*
		* Iterate and validate a match
		*/
		for (int i = 0; i < m_Generators.GetCursor(); i++)
		{
			/*
			* Get generator layout object
			*/
			WindowLayout* layout = m_Generators[i]();

			/*
			* Validate
			*/
			if (layout->GetType() == type)
			{
				delete layout;
				return true;
			}
			delete layout;
		}
		return false;
	}

	Rudy::Array<WindowLayoutGenerator> WindowLayoutGeneratorRegistry::GetGenerators() const
	{
		return m_Generators;
	}

	WindowLayoutGeneratorFactory::WindowLayoutGeneratorFactory(WindowLayoutGenerator generator)
	{
		WindowLayoutGeneratorRegistry::GetCurrent().RegisterGenerator(generator);
	}

}