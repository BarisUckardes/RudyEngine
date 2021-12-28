#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
namespace Rudy
{
	class RUDY_API IndexBuffer : public GraphicsDeviceObject
	{
	public:
		/// <summary>
		/// Sets the index buffer data
		/// </summary>
		/// <param name="dataPtr"></param>
		/// <param name="count"></param>
		/// <param name="sizePerElement"></param>
		void SetData(unsigned char* dataPtr, unsigned int count, unsigned int sizePerElement);

		/// <summary>
		/// Returns the element count for this index buffer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetElementCount() const;

		/// <summary>
		/// Returns the native handle for this index buffer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE virtual void* GetNativeHandle() const = 0;
	protected:
		IndexBuffer(GraphicsDevice* device);
		virtual ~IndexBuffer() = default;
		/// <summary>
		/// User implementation of the SetData method
		/// </summary>
		/// <param name="dataPtr"></param>
		/// <param name="count"></param>
		/// <param name="sizePerElement"></param>
		virtual void SetDataCore(unsigned char* dataPtr, unsigned int count, unsigned int sizePerElement) = 0;
	private:
		unsigned int m_ElementCount;
	};


}