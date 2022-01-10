#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Long term job
	/// </summary>
	class RUDY_API Job
	{
	public:
		Job() = default;
		~Job() = default;

		/// <summary>
		/// Starts the execution of this job
		/// </summary>
		void ExecuteJob();
		void WaitForFinish();
	};
}