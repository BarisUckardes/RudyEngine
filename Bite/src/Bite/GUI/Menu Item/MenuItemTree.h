#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Array.h>
#include <Bite/GUI/Menu Item/MenuItemGeneration.h>
namespace Bite
{
	/// <summary>
	/// Represents a menu tree for gui renderings
	/// </summary>
	class BITE_API MenuItemTree
	{
	public:
		MenuItemTree();
		~MenuItemTree();

		/// <summary>
		/// Inserts a new menu item path source
		/// </summary>
		/// <param name="sourceText"></param>
		/// <param name="generator"></param>
		void InsertSourceText(const Rudy::String& sourceText,MenuItemReflectionGenerator generator);

		/// <summary>
		/// Invokes the generator of this menu item tree
		/// </summary>
		void Invoke() const;

		/// <summary>
		/// Returns the name of the tree node
		/// </summary>
		/// <returns></returns>
		Rudy::String GetName() const;

		/// <summary>
		/// Sets the name of the tree node
		/// </summary>
		/// <param name="name"></param>
		void SetName(const Rudy::String& name);

		/// <summary>
		/// Returns the sub trees
		/// </summary>
		/// <returns></returns>
		Rudy::Array<MenuItemTree*> GetSubTrees() const;

		/// <summary>
		/// Returns whether has sub trees or not
		/// </summary>
		/// <returns></returns>
		bool HasSubTrees() const;
	private:
		/// <summary>
		/// Generates and returns the splitted strings of the full menu path
		/// </summary>
		/// <param name="sourceText"></param>
		/// <returns></returns>
		Rudy::Array<Rudy::String> GetTreeNodes(const Rudy::String& sourceText) const;

		/// <summary>
		/// Inserts the noded strings with their generators
		/// </summary>
		/// <param name="nodes"></param>
		/// <param name="generator"></param>
		void InsertTreeNodes(Rudy::Array<Rudy::String> nodes,MenuItemReflectionGenerator generator);

		/// <summary>
		/// Sets this menu item's generator
		/// </summary>
		/// <param name="generator"></param>
		void SetGenerator(MenuItemReflectionGenerator generator);

		Rudy::Array<MenuItemTree*> m_SubTrees;
		MenuItemReflectionGenerator m_Generator;
		Rudy::String m_Name;
	};


}