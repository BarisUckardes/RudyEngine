#include "MainMenuBarGUIModule.h"
#include <Bite/GUI/Menu Item/MenuItemGeneration.h>
#include <Bite/GUI/Menu Item/MenuItemTree.h>
#include <Bite/GUI/Module/MainMenu/Templates/MainMenuItemTemplates.h>
#include <Rudy/ImGui/Commands/ImGuiRenderCommands.h>
#include <Bite/GUI/Painter/GUIPainter.h>
#include <Bite/Editor/Session/EditorSession.h>
namespace Bite
{
	void MainMenuBarGUIModule::OnAttach()
	{
		m_Tree = new MenuItemTree();
		SetupMenuItemTrees();
	}

	void MainMenuBarGUIModule::OnUpdate()
	{
		if (GetOwnerSession()->GetSessionPainter()->GetRenderCommands()->BeginMainMenuBar())
		{
			RenderMenuItemTree(m_Tree);
			GetOwnerSession()->GetSessionPainter()->GetRenderCommands()->FinalizeMainMenuBar();
		}
	}

	void MainMenuBarGUIModule::OnDetach()
	{
		delete m_Tree;
	}
	void MainMenuBarGUIModule::RenderMenuItemTree(const MenuItemTree* tree)
	{
		/*
		* Check if its root or not
		*/
		if (tree->GetName() == "Root")
		{
			Rudy::Array<MenuItemTree*> subTrees = tree->GetSubTrees();
			for (unsigned int subIndex = 0; subIndex < subTrees.GetCursor(); subIndex++)
				RenderMenuItemTree(subTrees[subIndex]);
			return;
		}

		/*
		* If its not root
		*/
		if (tree->HasSubTrees())
		{
			if (GetOwnerSession()->GetSessionPainter()->GetRenderCommands()->BeginMenu(tree->GetName()))
			{
				Rudy::Array<MenuItemTree*>subTrees = tree->GetSubTrees();
				for (unsigned int subIndex = 0; subIndex < subTrees.GetCursor(); subIndex++)
					RenderMenuItemTree(subTrees[subIndex]);

				GetOwnerSession()->GetSessionPainter()->GetRenderCommands()->FinalizeMenu();
			}
		}
		else
		{
			if (GetOwnerSession()->GetSessionPainter()->GetRenderCommands()->CreateMenuItem(tree->GetName()))
			{
				tree->Invoke();
			}
		}
	}
	void MainMenuBarGUIModule::SetupMenuItemTrees()
	{
		/*
		* Get reflection definitions
		*/
		Rudy::Array<MenuItemReflectionGenerator> generators = MenuItemLayoutGeneratorRegistry::GetCurrent().GetGenerators();

		/*
		* Setup main menu item tree
		*/
		for (unsigned int generatorIndex = 0; generatorIndex < generators.GetCursor(); generatorIndex++)
		{
			/*
			* Insert source text
			*/
			m_Tree->InsertSourceText(generators[generatorIndex]()->GetItemName(), generators[generatorIndex]);
		}
	}
}
