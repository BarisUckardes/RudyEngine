#include "VertexBuffer.h"

namespace Rudy
{
	VertexBuffer::~VertexBuffer()
	{

	}
	VertexLayout VertexBuffer::GetVertexLayout() const
	{
		return m_VertexLayout;
	}
	unsigned int VertexBuffer::GetVertexCount() const
	{
		return m_VertexCount;
	}
	void VertexBuffer::SetData(const unsigned char* dataPtr, const unsigned int elementSize, const unsigned int elementCount)
	{
		/*
		* Call user defined implementation
		*/
		SetDataCore(dataPtr, elementSize, elementCount);

		/*
		* Set vertex layout and element count
		*/
		m_VertexLayout = m_VertexLayout;
		m_VertexCount = elementCount;
	}
	VertexBuffer::VertexBuffer()
	{

	}
	GraphicsDevice* VertexBuffer::GetOwnerGraphicsDevice() const
	{
		return GraphicsDeviceObject::GetOwnerGraphicsDevice();
	}
}