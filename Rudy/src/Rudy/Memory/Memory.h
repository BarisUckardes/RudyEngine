#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{

	/// <summary>
	/// Memory utility class
	/// </summary>
	class RUDY_API Memory
	{
	public:
		Memory() = delete;
		~Memory() = delete;

		/// <summary>
		/// Copies memory from one place to an another
		/// </summary>
		/// <param name="destination"></param>
		/// <param name="source"></param>
		/// <param name="byteCount"></param>
		FORCEINLINE static void MemoryCopy(void* destination, void* source, unsigned long byteCount);

	};
}