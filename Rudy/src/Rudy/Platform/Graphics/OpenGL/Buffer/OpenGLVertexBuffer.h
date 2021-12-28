#pragma once
#include <Rudy/Graphics/Buffer/VertexBuffer.h>

namespace Rudy
{
	/// <summary>
	/// Opengl implementation of a vertex buffer
	/// </summary>
	class RUDY_API OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(GraphicsDevice* device);
		virtual ~OpenGLVertexBuffer() override;

		virtual void* GetNativeHandle() const override;
	protected:
		virtual void SetDataCore(const unsigned char* dataPtr, const unsigned int elementSize, const unsigned int elementCount, const VertexLayout& vertexLayout) override;
	private:
		unsigned int m_Handles[2];
	};


}