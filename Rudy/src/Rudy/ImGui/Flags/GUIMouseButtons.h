#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
    /// <summary>
    /// Supported gui mosue buttons
    /// </summary>
    enum class RUDY_API GUIMouseButtons
    {
        Left = 0,
        Right = 1,
        Middle = 2,
        COUNT = 5
    };

    inline GUIMouseButtons operator | (GUIMouseButtons a, GUIMouseButtons b)
    {
        return GUIMouseButtons((int)a | (int)b);
    }

    inline GUIMouseButtons& operator |= (GUIMouseButtons& a, GUIMouseButtons b)
    {
        a = a | b;
        return a;
    }

}