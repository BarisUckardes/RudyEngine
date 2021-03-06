#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
    /*
    * Dock node behaviour flags
    */
    enum class RUDY_API GUIDockNodeFlags
    {
        None = 0,
        KeepAliveOnly = 1 << 0,   // Shared       // Don't display the dockspace node but keep it alive. Windows docked into this dockspace node won't be undocked.
        //NoCentralNode              = 1 << 1,   // Shared       // Disable Central Node (the node which can stay empty)
        NoDockingInCentralNode = 1 << 2,   // Shared       // Disable docking inside the Central Node, which will be always kept empty.
        PassthruCentralNode = 1 << 3,   // Shared       // Enable passthru dockspace: 1) DockSpace() will render a ImGuiCol_WindowBg background covering everything excepted the Central Node when empty. Meaning the host window should probably use SetNextWindowBgAlpha(0.0f) prior to Begin() when using this. 2) When Central Node is empty: let inputs pass-through + won't display a DockingEmptyBg background. See demo for details.
        NoSplit = 1 << 4,   // Shared/Local // Disable splitting the node into smaller nodes. Useful e.g. when embedding dockspaces into a main root one (the root one may have splitting disabled to reduce confusion). Note: when turned off, existing splits will be preserved.
        NoResize = 1 << 5,   // Shared/Local // Disable resizing node using the splitter/separators. Useful with programmatically setup dockspaces.
        AutoHideTabBar = 1 << 6    // Shared/Local // Tab bar will automatically hide when there is a single window in the dock node.
    };

    inline GUIDockNodeFlags operator | (GUIDockNodeFlags a, GUIDockNodeFlags b)
    {
        return GUIDockNodeFlags((int)a | (int)b);
    }

    inline GUIDockNodeFlags& operator |= (GUIDockNodeFlags& a, GUIDockNodeFlags b)
    {
        a = a | b;
        return a;
    }
}