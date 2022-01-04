#include "MenuItemTree.h"

namespace Bite
{
	MenuItemTree::MenuItemTree()
	{
		m_Name = "Root";
	}
	MenuItemTree::~MenuItemTree()
	{
		/*
		* Delete sub trees
		*/
		for (unsigned int treeIndex = 0; treeIndex < m_SubTrees.GetCursor(); treeIndex++)
			delete m_SubTrees[treeIndex];

		/*
		* Clear the container
		*/
		m_SubTrees.Clear();
	}
	void MenuItemTree::InsertSourceText(const Rudy::String& sourceText, MenuItemReflectionGenerator generator)
	{
		/*
		* Create item tree representation
		*/
		Rudy::Array<Rudy::String> nodes = GetTreeNodes(sourceText);

		/*
		* Validate nodes
		*/
		if (nodes.GetCursor() < 0)
			return;

		/*
		* Check sub nodes
		*/
		for (unsigned int i = 0; i < m_SubTrees.GetCursor(); i++)
		{
			if (m_SubTrees[i]->GetName() == nodes[0]) // its the sub node 
			{
				/*
				* Remove the node and forward it
				*/
				nodes.RemoveIndex(0);

				/*
				* Validate node list
				*/
				if (nodes.GetCursor() <= 0)
				{
					return;
				}

				/*
				* Insert nodes
				*/
				m_SubTrees[i]->InsertTreeNodes(nodes, generator);
				return;
			}
		}

		/*
		* If no fitting node found then create new Sub tree
		*/
		MenuItemTree* newTree = new MenuItemTree();
		m_SubTrees.Add(newTree);

		/*
		* Set name
		*/
		newTree->SetName(nodes[0]);

		/*
		* Erase current node and forward the nodes
		*/
		nodes.RemoveIndex(0);


		/*
		* Validate node list
		*/
		if (nodes.GetCursor() <= 0)
		{
			newTree->SetGenerator(generator);
			return;
		}

		/*
		* Insert new nodes
		*/
		newTree->InsertTreeNodes(nodes, generator);
	}

	void MenuItemTree::Invoke() const
	{
		MenuItemLayout* layout = m_Generator();
		layout->OnMenuItemClicked();
		delete layout;
	}

	Rudy::String MenuItemTree::GetName() const
	{
		return m_Name;
	}

	void MenuItemTree::SetName(const Rudy::String& name)
	{
		m_Name = name;
	}

	Rudy::Array<MenuItemTree*> MenuItemTree::GetSubTrees() const
	{
		return m_SubTrees;
	}

	bool MenuItemTree::HasSubTrees() const
	{
		return m_SubTrees.GetCursor() > 0;
	}

	Rudy::Array<Rudy::String> MenuItemTree::GetTreeNodes(const Rudy::String& sourceText) const
	{
		Rudy::Array<Rudy::String> nodes;
		Rudy::String dummy;

		/*
		* Break into nodes
		*/
		for (unsigned int i = 0; i < sourceText.GetCursor(); i++)
		{
			/*
			* Check for slash
			*/
			if (sourceText[i] == '/')
			{
				nodes.Add(dummy);
				dummy.Clear();
				continue;
			}
			dummy += sourceText[i];
		}

		/*
		* Push the last one
		*/
		nodes.Add(dummy);

		return nodes;
	}

	void MenuItemTree::InsertTreeNodes(Rudy::Array<Rudy::String> nodes, MenuItemReflectionGenerator generator)
	{
		/*
		* Check if sub nodes contains the current node
		*/
		for (unsigned int i = 0; i < m_SubTrees.GetCursor(); i++)
		{
			if (m_SubTrees[i]->GetName() == nodes[0]) // fitting node found forward it
			{
				nodes.RemoveIndex(+0);

				/*
				* Validate node list
				*/
				if (nodes.GetCursor() <= 0)
				{
					return;
				}

				m_SubTrees[i]->InsertTreeNodes(nodes, generator);
				return;
			}
		}

		/*
		* If no fitting node found then create new Sub tree
		*/
		MenuItemTree* newTree = new MenuItemTree();
		m_SubTrees.Add(newTree);

		/*
		* Set name
		*/
		newTree->SetName(nodes[0]);

		/*
		* Erase current node and forward the nodes
		*/
		nodes.RemoveIndex(0);

		/*
		* Validate node list
		*/
		if (nodes.GetCursor() <= 0)
		{
			newTree->SetGenerator(generator);
			return;
		}

		newTree->InsertTreeNodes(nodes, generator);
	}

	void MenuItemTree::SetGenerator(MenuItemReflectionGenerator generator)
	{
		m_Generator = generator;
	}

}