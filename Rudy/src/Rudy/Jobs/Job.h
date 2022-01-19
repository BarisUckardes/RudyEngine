#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	class RUDY_API Job
	{
	public:
		void Initialize(void* parameters = nullptr);
		void Execute();
		void WaitForFinish();
	protected:
		virtual void ExecuteCore() = 0;
	private:

	};


}