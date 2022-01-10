#pragma once
#include <Rudy/Core/Symbols.h>


namespace Rudy
{
	class RUDY_API JobPool
	{
	public:
		JobPool(unsigned int jobCount);
		~JobPool();

		void CreateJob();

	private:
		unsigned int m_TotalJobCount;
		unsigned int m_ActiveJobCount;
	};


}