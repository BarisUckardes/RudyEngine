#pragma once
#include <Rudy/Graphics/Command/RenderCommand.h>

namespace Rudy
{
	class RUDY_API OpenGLSetVertexBufferRC : public RenderCommand
	{
	public:
		OpenGLSetVertexBufferRC(unsigned int vertexArrayID, unsigned int vertexBufferID);
		~OpenGLSetVertexBufferRC() = default;

		virtual void Execute() override;
	private:
		unsigned int m_VertexArrayID;
		unsigned int m_VertexBufferID;
	};


}