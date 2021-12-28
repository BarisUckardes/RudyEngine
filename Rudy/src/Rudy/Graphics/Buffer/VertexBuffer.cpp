#include "VertexBuffer.h"

namespace Rudy
{
	VertexLayout VertexBuffer::GetVertexLayout() const
	{
		return m_VertexLayout;
	}
	unsigned int VertexBuffer::GetVertexCount() const
	{
		return m_VertexCount;
	}
	void VertexBuffer::SetData(const unsigned char* dataPtr, const unsigned int elementSize, const unsigned int elementCount, const VertexLayout& vertexLayout)
	{
		/*
		* Call user defined implementation
		*/
		SetDataCore(dataPtr, elementSize, elementCount, vertexLayout);

		/*
		* Set vertex layout and element count
		*/
		m_VertexLayout = m_VertexLayout;
		m_VertexCount = elementCount;
	}
	VertexBuffer::VertexBuffer(GraphicsDevice* device) : GraphicsDeviceObject(device)
	{

	}
	GraphicsDevice* VertexBuffer::GetOwnerGraphicsDevice() const
	{
		return GraphicsDeviceObject::GetOwnerGraphicsDevice();
	}
}