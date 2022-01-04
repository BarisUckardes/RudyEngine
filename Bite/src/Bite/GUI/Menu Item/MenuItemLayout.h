#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
namespace Bite
{
	/// <summary>
	/// Base class for all menu item layouts for gui rendering
	/// </summary>
	class BITE_API MenuItemLayout
	{
	public:
		MenuItemLayout() = default;
		~MenuItemLayout() = default;

		/// <summary>
		/// Called when this menu item clicked
		/// </summary>
		virtual void OnMenuItemClicked() = 0;

		/// <summary>
		/// Node name of the menu item
		/// </summary>
		/// <returns></returns>
		virtual Rudy::String GetItemName() const;
	};

}
