#pragma once
#include <Rudy/Graphics/Buffer/ConstantBuffer.h>

namespace Rudy
{
	/// <summary>
	/// Opengl implementation of a constant buffer
	/// </summary>
	class RUDY_API OpenGLConstantBuffer : public ConstantBuffer
	{
	public:
		OpenGLConstantBuffer(const String& bufferName, unsigned int bufferSize);
		~OpenGLConstantBuffer() = default;

		virtual void* GetNativeHandle() const override { return nullptr; }
		virtual void SetBufferData(void* dataPtr) override;
		virtual void Initialize() override;
	private:
		unsigned int m_BufferID;
	};


}