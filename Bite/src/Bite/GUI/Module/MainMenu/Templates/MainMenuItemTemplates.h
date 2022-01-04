#pragma once
#include <Bite/GUI/Menu Item/MenuItemLayout.h>
#include <Bite/GUI/Menu Item/MenuItemGeneration.h>
#include <Bite/GUI/Menu Item/MenuItemTree.h>
namespace Bite
{
	GENERATE_MENU_ITEM(TestMenuItem, "Test/TESTTT");
	void TestMenuItem::OnMenuItemClicked()
	{
	}
}