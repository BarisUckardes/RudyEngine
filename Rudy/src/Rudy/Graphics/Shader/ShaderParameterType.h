#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported shader parameter types
	/// </summary>
	enum class RUDY_API ShaderParameterType
	{
        Undefined = -1,
        Float = 0,
        Vector2 = 1,
        Vector3 = 2,
        Vector4 = 3,
        Color = 4,
        Matrix3x3 = 5,
        Matrix4x4 = 6,
        Texture2D = 7,
        Int = 8,
        UInt = 9
	};
}