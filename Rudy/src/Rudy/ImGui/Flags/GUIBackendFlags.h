#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
    /// <summary>
    /// Backend behaviour flags
    /// </summary>
    enum class RUDY_API GUIBackendFlags 
    {
        None = 0,
        HasGamepad = 1 << 0,   // Backend Platform supports gamepad and currently has one connected.
        HasMouseCursors = 1 << 1,   // Backend Platform supports honoring GetMouseCursor() value to change the OS cursor shape.
        HasSetMousePos = 1 << 2,   // Backend Platform supports io.WantSetMousePos requests to reposition the OS mouse position (only used if ImGuiConfigFlags_NavEnableSetMousePos is set).
        RendererHasVtxOffset = 1 << 3,   // Backend Renderer supports ImDrawCmd::VtxOffset. This enables output of large meshes (64K+ vertices) while still using 16-bit indices.

        // [BETA] Viewports
        PlatformHasViewports = 1 << 10,  // Backend Platform supports multiple viewports.
        HasMouseHoveredViewport = 1 << 11,  // Backend Platform supports setting io.MouseHoveredViewport to the viewport directly under the mouse _IGNORING_ viewports with the ImGuiViewportFlags_NoInputs flag and _REGARDLESS_ of whether another viewport is focused and may be capturing the mouse. This information is _NOT EASY_ to provide correctly with most high-level engines! Don't set this without studying _carefully_ how the backends handle ImGuiViewportFlags_NoInputs!
        RendererHasViewports = 1 << 12   // Backend Renderer supports multiple viewports.
    };

    inline GUIBackendFlags operator | (GUIBackendFlags a, GUIBackendFlags b)
    {
        return GUIBackendFlags((int)a | (int)b);
    }

    inline GUIBackendFlags& operator |= (GUIBackendFlags& a, GUIBackendFlags b)
    {
        a = a | b;
        return a;
    }

}