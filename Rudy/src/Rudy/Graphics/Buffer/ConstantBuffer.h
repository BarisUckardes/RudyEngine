#pragma once
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
#include <Rudy/Memory/String.h>
namespace Rudy
{
	/// <summary>
	/// A constant buffer which represetns the global allocated memory
	/// </summary>
	class RUDY_API ConstantBuffer : public GraphicsDeviceObject
	{
	public:
		ConstantBuffer(const String& name, unsigned int size);
		virtual ~ConstantBuffer() = 0;
		/// <summary>
		/// Returns the buffer name
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetBufferName() const;

		/// <summary>
		/// Returns the buffer size allocated on the gpu
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetBufferSize() const;

		/// <summary>
		/// Sets the buffer data
		/// </summary>
		/// <param name="dataPtr"></param>
		virtual void SetBufferData(void* dataPtr) = 0;

		/// <summary>
		/// Graphics api implementation of the buffer intialization
		/// </summary>
		/// <param name="size"></param>
		virtual void Initialize() = 0;
	private:
		String m_BufferName;
		unsigned int m_BufferSize;
	};


}