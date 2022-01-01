#include "ConstantBuffer.h"

namespace Rudy
{
	String ConstantBuffer::GetBufferName() const
	{
		return m_BufferName;
	}
	unsigned int ConstantBuffer::GetBufferSize() const
	{
		return m_BufferSize;
	}
	ConstantBuffer::ConstantBuffer(const String& name, unsigned int bufferSize)
	{
		/*
		* Set buffer properties
		*/
		m_BufferName = name;
		m_BufferSize = bufferSize;
	}
}