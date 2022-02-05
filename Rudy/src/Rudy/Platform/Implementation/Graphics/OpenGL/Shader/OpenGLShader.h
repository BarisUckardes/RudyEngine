#pragma once
#include <Rudy/Graphics/Shader/Shader.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL implementations of a shader
	/// </summary>
	class RUDY_API OpenGLShader : public Shader
	{
	public:
		OpenGLShader(ShaderStage stage);
		~OpenGLShader() = default;

		// Inherited via Shader
		virtual void* GetNativeHandle() const override;
		virtual void CompileCore(const String& source, bool& isCompiled, String& errorMessage) override;
	private:
		unsigned int m_ShaderID;
	};


}