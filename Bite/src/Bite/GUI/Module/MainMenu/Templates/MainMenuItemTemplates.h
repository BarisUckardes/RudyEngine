#pragma once
#include <Bite/GUI/Menu Item/MenuItemLayout.h>
#include <Bite/GUI/Menu Item/MenuItemGeneration.h>
#include <Bite/GUI/Menu Item/MenuItemTree.h>
#include <Bite/GUI/Module/Window/Templates/WorldObserverGUIWindow.h>
#include <Bite/GUI/Module/Window/Templates/DomainObserverGUIWindow.h>
#include <Bite/GUI/Module/Window/GUIWindowManager.h>

namespace Bite
{
	GENERATE_MENU_ITEM(WorldObserverWindowMenuItem, "Windows/World Observer");
	void WorldObserverWindowMenuItem::OnMenuItemClicked()
	{
		GUIWindowManager::Get()->RegisterWindow(WorldObserverGUIWindow::GetStaticType());
	}

	GENERATE_MENU_ITEM(DomainObserverWindowMenuItem, "Windows/Domain Observer");
	void DomainObserverWindowMenuItem::OnMenuItemClicked()
	{
		GUIWindowManager::Get()->RegisterWindow(DomainObserverGUIWindow::GetStaticType());
	}
}