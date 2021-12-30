#include "ShaderProgram.h"
#include <Rudy/Graphics/Shader/Shader.h>
namespace Rudy
{
    Array<Shader*> ShaderProgram::GetShaders() const
    {
        return m_Shaders;
    }
    String ShaderProgram::GetCategory() const
    {
        return m_Category;
    }
    String ShaderProgram::GetShaderName() const
    {
        return m_ShaderName;
    }
    String ShaderProgram::GetLastErrorMessage() const
    {
        return m_LastErrorMessage;
    }
    bool ShaderProgram::IsLinked() const
    {
        return m_Linked;
    }
    void ShaderProgram::RegisterLinkListener(Delegate<void,void*>* listener)
    {
        m_LinkedListeners.Add(listener);
    }
    void ShaderProgram::RemoveLinkListener(Delegate<void, void*>* listener)
    {
        m_LinkedListeners.Remove(listener);
    }
    void ShaderProgram::LinkProgram(Array<Shader*>& shaders)
    {
        /*
        * Remove former shader compile listeners 
        */
        for (int i = 0; i < m_Shaders.GetCursor(); i++)
        {
            m_Shaders[i]->RemoveCompileListener(m_ShaderCompileListener);
        }
        m_Shaders.Clear();

        /*
        * Call link program implementation
        */
        bool isLinked = false;
        String errorMessage;
        LinkProgramCore(shaders, isLinked, errorMessage);

        /*
        * Register listener to shaders
        */
        for (int i = 0; i < shaders.GetCursor(); i++)
        {
            shaders[i]->RegisterCompileListener(m_ShaderCompileListener);
        }

        /*
        * Invoke all listeners
        */
        for (int i = 0; i < m_LinkedListeners.GetCursor(); i++)
        {
            m_LinkedListeners[i]->Invoke(nullptr);
        }

        /*
        * Set variables
        */
        m_Shaders = shaders;
        m_LastErrorMessage = errorMessage;
        m_Linked = isLinked;
    }
    ShaderProgram::ShaderProgram()
    {
        /*
        * Create new listener
        */
        m_ShaderCompileListener = new Delegate<void,void*>(RUDY_BIND_EVENT(ShaderProgram::OnSubShaderCompiled));
    }
    ShaderProgram::~ShaderProgram()
    {
        delete m_ShaderCompileListener;
        m_ShaderCompileListener = nullptr;
    }
    void ShaderProgram::OnSubShaderCompiled(void*)
    {

    }
}