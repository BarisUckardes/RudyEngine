#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
    enum class RUDY_API GUIConfigFlags
    {
        None = 0,
        NavEnableKeyboard = 1 << 0,   // Master keyboard navigation enable flag. NewFrame() will automatically fill io.NavInputs[] based on io.KeysDown[].
        NavEnableGamepad = 1 << 1,   // Master gamepad navigation enable flag. This is mostly to instruct your imgui backend to fill io.NavInputs[]. Backend also needs to set ImGuiBackendFlags_HasGamepad.
        NavEnableSetMousePos = 1 << 2,   // Instruct navigation to move the mouse cursor. May be useful on TV/console systems where moving a virtual mouse is awkward. Will update io.MousePos and set io.WantSetMousePos=true. If enabled you MUST honor io.WantSetMousePos requests in your backend, otherwise ImGui will react as if the mouse is jumping around back and forth.
        NavNoCaptureKeyboard = 1 << 3,   // Instruct navigation to not set the io.WantCaptureKeyboard flag when io.NavActive is set.
        NoMouse = 1 << 4,   // Instruct imgui to clear mouse position/buttons in NewFrame(). This allows ignoring the mouse information set by the backend.
        NoMouseCursorChange = 1 << 5,   // Instruct backend to not alter mouse cursor shape and visibility. Use if the backend cursor changes are interfering with yours and you don't want to use SetMouseCursor() to change mouse cursor. You may want to honor requests from imgui by reading GetMouseCursor() yourself instead.

        // [BETA] Docking
        DockingEnable = 1 << 6,   // Docking enable flags.

        // [BETA] Viewports
        // When using viewports it is recommended that your default value for ImGuiCol_WindowBg is opaque (Alpha=1.0) so transition to a viewport won't be noticeable.
        ViewportsEnable = 1 << 10,  // Viewport enable flags (require both ImGuiBackendFlags_PlatformHasViewports + ImGuiBackendFlags_RendererHasViewports set by the respective backends)
        DpiEnableScaleViewports = 1 << 14,  // [BETA: Don't use] FIXME-DPI: Reposition and resize imgui windows when the DpiScale of a viewport changed (mostly useful for the main viewport hosting other window). Note that resizing the main window itself is up to your application.
        DpiEnableScaleFonts = 1 << 15,  // [BETA: Don't use] FIXME-DPI: Request bitmap-scaled fonts to match DpiScale. This is a very low-quality workaround. The correct way to handle DPI is _currently_ to replace the atlas and/or fonts in the Platform_OnChangedViewport callback, but this is all early work in progress.

        // User storage (to allow your backend/engine to communicate to code that may be shared between multiple projects. Those flags are not used by core Dear ImGui)
        IsSRGB = 1 << 20,  // Application is SRGB-aware.
        IsTouchScreen = 1 << 21   // Application is using a touch screen instead of a mouse.
    };

    inline GUIConfigFlags operator | (GUIConfigFlags a, GUIConfigFlags b)
    {
        return GUIConfigFlags((int)a | (int)b);
    }

    inline GUIConfigFlags& operator |= (GUIConfigFlags& a, GUIConfigFlags b)
    {
        a = a | b;
        return a;
    }

}