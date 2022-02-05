#pragma once
#include <Rudy/Graphics/Buffer/IndexBuffer.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL implementation of an index buffer
	/// </summary>
	class RUDY_API OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer() = default;
		~OpenGLIndexBuffer() = default;

		virtual void* GetNativeHandle() const override;
	protected:
		virtual void SetDataCore(unsigned char* dataPtr, unsigned int count, unsigned int sizePerElement) override;
	private:
		unsigned int m_IndexBufferID;
	};


}