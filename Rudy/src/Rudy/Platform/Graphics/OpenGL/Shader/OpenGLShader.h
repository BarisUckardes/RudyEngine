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
		OpenGLShader(GraphicsDevice* device);
		virtual ~OpenGLShader() override;

		// Inherited via Shader
		virtual void* GetNativeHandle() const override;
		virtual void CompileCore(const String& source, bool& isCompiled, String& errorMessage) override;
	private:
		unsigned int m_ShaderID;
	};


}