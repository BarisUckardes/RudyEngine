#pragma once
#include <Rudy/Memory/String.h>
#include <Rudy/Core/Symbols.h>
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
#include <Rudy/Graphics/Shader/ShaderStage.h>
#include <Rudy/Application/Events/Delegate.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{
	/// <summary>
	/// Graphics api agnostic shader wrapper
	/// </summary>
	class RUDY_API Shader : public GraphicsDeviceObject
	{
	public:
		Shader(ShaderStage stage);
		virtual ~Shader() = 0;

		/// <summary>
		/// Returns the stage of this shader
		/// </summary>
		/// <returns></returns>
		FORCEINLINE ShaderStage GetStage() const;

		/// <summary>
		/// Returns the source text of this shader
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetSource() const;

		/// <summary>
		/// Returns the last error message of compilation
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetLastErrorMessage() const;

		/// <summary>
		/// Returns whether this shader is successfully compiled
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsCompiled() const;

		/// <summary>
		/// Compiles the shader with the given source text
		/// </summary>
		/// <param name="source"></param>
		void Compile(const String& source);

		/// <summary>
		/// Registers anew listener for the compile
		/// </summary>
		/// <param name="delegate"></param>
		void RegisterCompileListener(Delegate<void, void*>* delegate);

		/// <summary>
		/// Removes a compile listener
		/// </summary>
		/// <param name="delegate"></param>
		void RemoveCompileListener(Delegate<void, void*>* delegate);
	protected:
		/// <summary>
		/// User implementation of compile method
		/// </summary>
		/// <param name="source"></param>
		virtual void CompileCore(const String& source,bool& isCompiled,String& errorMessage) = 0;
	private:
		Array<Delegate<void, void*>*> m_CompileListeners;
		ShaderStage m_Stage;
		String m_Source;
		String m_LastErrorMessage;
		bool m_Compiled;
	};


}