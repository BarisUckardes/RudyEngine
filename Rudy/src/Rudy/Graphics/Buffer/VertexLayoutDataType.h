#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported vertex layout data type
	/// </summary>
	enum class RUDY_API VertexLayoutDataType
	{
		None = 0,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, In4,
		Bool
	};

	
}