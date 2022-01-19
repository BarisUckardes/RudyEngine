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
		OpenGLVertexBuffer() = default;
		~OpenGLVertexBuffer() = default;;

		// Inherited via VertexBuffer
		virtual void Initialize(const VertexLayout& vertexLayout) override;
		virtual void* GetNativeHandle() const override;
	protected:
		virtual void SetDataCore(const unsigned char* dataPtr, const unsigned int elementSize, const unsigned int elementCount) override;
		virtual void FreeDeviceObjectCore() override;
	private:
		unsigned int m_Handles[2];
	};


}