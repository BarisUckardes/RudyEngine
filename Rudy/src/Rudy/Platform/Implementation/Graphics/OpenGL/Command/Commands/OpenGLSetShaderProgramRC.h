#pragma once
#include <Rudy/Graphics/Command/RenderCommand.h>

namespace Rudy
{
	class RUDY_API OpenGLSetShaderProgramRC : public RenderCommand
	{
	public:
		OpenGLSetShaderProgramRC(unsigned int programID);
		~OpenGLSetShaderProgramRC() = default;

		virtual void Execute() override;
	private:
		unsigned int m_ProgramID;
	};


}