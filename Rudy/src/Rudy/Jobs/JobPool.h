#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	class Job;
	class RUDY_API JobPool
	{
	public:
		JobPool(unsigned int threadCount);
		~JobPool();

		Job* AllocateJob();

	};


}