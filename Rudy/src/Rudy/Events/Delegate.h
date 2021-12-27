#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Core/Events.h>
#include <functional>
namespace Rudy
{
	template<typename TReturn,typename...TParameters>
	/// <summary>
	/// Simple delegate wrapper
	/// </summary>
	/// <typeparam name="...TParameters"></typeparam>
	/// <typeparam name="TReturn"></typeparam>
	class RUDY_API Delegate
	{
	public:
		Delegate(std::function<TReturn(TParameters...)> function)
		{
			m_FunctionPtr = function;
		}
		Delegate() = delete;
		~Delegate()
		{

		}

		/// <summary>
		/// Invokes the delegate
		/// </summary>
		/// <param name="...parameters"></param>
		void Invoke(TParameters... parameters)
		{
			m_FunctionPtr(parameters...);
		}
	private:
		std::function<TReturn(TParameters...)> m_FunctionPtr;
	};




}