#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Array.h>

namespace Bite
{
	class BITE_API MenuItemTree
	{
	public:
		MenuItemTree();
		~MenuItemTree();

		void InsertSourceText(const Rudy::String& sourceText);
		void Invoke() const;
		Rudy::String GetName() const;
		void SetName(const Rudy::String& name);
		Rudy::Array<MenuItemTree*> GetSubTrees() const;
		bool HasSubTrees() const;
	private:
		Rudy::Array<Rudy::String> GetTreeNodes(const Rudy::String& sourceText) const;
		void InsertTreeNodes(Rudy::Array<Rudy::String> nodes);
		void SetDefinition();

		Rudy::Array<MenuItemTree*> m_SubTrees;
	};


}