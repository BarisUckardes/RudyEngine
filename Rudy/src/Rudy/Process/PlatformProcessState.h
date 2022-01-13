#pragma once

#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// The states of an os process
	/// </summary>
	enum class PlatformProcessState
	{
		/// <summary>
		/// The process is unitialized
		/// </summary>
		Undefined = 0,

		/// <summary>
		/// Process start information created, waiting for start
		/// </summary>
		Initialized = 1,

		/// <summary>
		/// Process is currenlt running
		/// </summary>
		Running = 2,

		/// <summary>
		/// Prompted wait for finish
		/// </summary>
		WaitingForFinish = 3,

		/// <summary>
		/// Process intialized,started and finalized
		/// </summary>
		Finalized = 4
	};
}