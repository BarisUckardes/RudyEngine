#include "Shader.h"

namespace Rudy
{
	void Shader::Compile(const String& source)
	{
		/*
		* Call user compile
		*/
		bool compileStatus = false;
		String compileMessage;
		CompileCore(source, compileStatus, compileMessage);

		/*
		* Invoke event
		*/
		for (int i = 0; i < m_CompileListeners.GetCursor(); i++)
		{
			m_CompileListeners[i]->Invoke(nullptr);
		}

		/*
		* Set new shader state
		*/
		m_Source = source;
		m_LastErrorMessage = compileMessage;
		m_Compiled = compileStatus;
	}
	ShaderStage Shader::GetStage() const
	{
		return m_Stage;
	}
	String Shader::GetSource() const
	{
		return m_Source;
	}
	String Shader::GetLastErrorMessage() const
	{
		return m_LastErrorMessage;
	}
	bool Shader::IsCompiled() const
	{
		return m_Compiled;
	}
	void Shader::RegisterCompileListener(Delegate<void, void*>* delegate)
	{
		m_CompileListeners.Add(delegate);
	}
	void Shader::RemoveCompileListener(Delegate<void, void*>* delegate)
	{
		m_CompileListeners.Remove(delegate);
	}
	Shader::Shader(ShaderStage stage)
	{
		m_Stage = stage;
	}
	Shader::~Shader()
	{

	}
}