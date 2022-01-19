#pragma once
#include <Rudy/Graphics/Command/RenderCommand.h>

namespace Rudy
{
	class RUDY_API OpenGLSetIndexBufferRC : public RenderCommand
	{
	public:
		OpenGLSetIndexBufferRC(unsigned int indexBufferID);
		~OpenGLSetIndexBufferRC() = default;

		virtual void Execute() override;
	private:
		unsigned int m_IndexBufferID;
	};


}