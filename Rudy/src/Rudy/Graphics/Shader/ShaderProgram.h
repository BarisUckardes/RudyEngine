#pragma once
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Events/Delegate.h>
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
namespace Rudy
{
	class GraphicsDevice;
	class Shader;

	/// <summary>
	/// Graphics api agnostic shader program wrapper
	/// </summary>
	class RUDY_API ShaderProgram : public GraphicsDeviceObject
	{
	public:
		ShaderProgram();
		virtual ~ShaderProgram() = 0;

		/// <summary>
		/// Returns all the shader this program linked into
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<Shader*> GetShaders() const;

		/// <summary>
		/// Returns the category of this program
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetCategory() const;

		/// <summary>
		/// Returns the shader name of this program
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetShaderName() const;

		/// <summary>
		/// Returns the last error message of this program
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetLastErrorMessage() const;

		/// <summary>
		/// Returns whether this program is linked or not
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsLinked() const;

		/// <summary>
		/// Registers a program link listener
		/// </summary>
		/// <param name="listener"></param>
		void RegisterLinkListener(Delegate<void, void*>* listener);

		/// <summary>
		/// Removes a program link listener
		/// </summary>
		/// <param name="listener"></param>
		void RemoveLinkListener(Delegate<void, void*>* listener);

		/// <summary>
		/// Links the program againts the given shaders
		/// </summary>
		/// <param name="shaders"></param>
		void LinkProgram(Array<Shader*>& shaders);
	protected:
		/// <summary>
		/// User defined link program implementation
		/// </summary>
		/// <param name="shaders"></param>
		/// <param name="linkState"></param>
		/// <param name="errorMessage"></param>
		virtual void LinkProgramCore(Array<Shader*>& shaders,bool& linkState,String& errorMessage) = 0;
	private:
		/// <summary>
		/// Called when one of the shaders of this program is compiled
		/// </summary>
		void OnSubShaderCompiled(void*);

		Array<Shader*> m_Shaders;
		Delegate<void,void*>* m_ShaderCompileListener;
		Array<Delegate<void,void*>*> m_LinkedListeners;
		String m_Category;
		String m_ShaderName;
		String m_LastErrorMessage;
		bool m_Linked;
	};


}