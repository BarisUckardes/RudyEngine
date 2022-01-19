#pragma once
#include <Rudy/Graphics/Command/RenderCommand.h>

namespace Rudy
{
	class RUDY_API OpenGLDrawIndexedRC : public RenderCommand
	{
	public:
		OpenGLDrawIndexedRC(unsigned int count);
		~OpenGLDrawIndexedRC() = default;

		virtual void Execute() override;
	private:
		unsigned int m_Count;
	};


}