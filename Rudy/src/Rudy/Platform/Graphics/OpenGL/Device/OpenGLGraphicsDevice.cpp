#include "OpenGLGraphicsDevice.h"
#include <Rudy/Windowing/Window.h>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <Rudy/Platform/Graphics/OpenGL/Buffer/OpenGLIndexBuffer.h>
#include <Rudy/Platform/Graphics/OpenGL/Buffer/OpenGLVertexBuffer.h>
#include <Rudy/Platform/Graphics/OpenGL/Texture/OpenGLTexture2D.h>
#include <Rudy/Platform/Graphics/OpenGL/Command/OpenGLCommandBuffer.h>
#include <Rudy/Platform/Graphics/OpenGL/Buffer/OpenGLConstantBuffer.h>
#include <Rudy/Platform/Graphics/OpenGL/Shader/OpenGLShader.h>
#include <Rudy/Platform/Graphics/OpenGL/Shader/OpenGLShaderProgram.h>
namespace Rudy
{
	OpenGLGraphicsDevice::OpenGLGraphicsDevice()
	{

	}
	void OpenGLGraphicsDevice::InitializeCore()
	{
		/*
		* Create opengl context out of the glfw context
		*/
		GLFWwindow* glfwWindow = (GLFWwindow*)GetTargetWindow()->GetNativePtr();

		/*
		* Make current glfw context
		*/
		glfwMakeContextCurrent(glfwWindow);

		/*
		* Load glad library
		*/
		gladLoadGL();

		/*
		* Set this graphics device's api type
		*/
		SetApiType(GraphicsAPIType::OpenGL);

		glDebugMessageCallback(
			[](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
			{
				if(severity == GL_DEBUG_SEVERITY_HIGH)
					printf("OPENGL ERROR: %s\n", message);
			}
			, nullptr);
	}
	void OpenGLGraphicsDevice::Swapbuffers()
	{
		glfwSwapBuffers((GLFWwindow*)(GetTargetWindow()->GetNativePtr()));
	}
	IndexBuffer* OpenGLGraphicsDevice::CreateIndexBuffer()
	{
		/*
		* Create new OpenGL index buffer
		*/
		OpenGLIndexBuffer* buffer = new OpenGLIndexBuffer();

		/*
		* Set device object
		*/
		SetDeviceObjectTargetDevice(buffer);

		return buffer;
	}
	VertexBuffer* OpenGLGraphicsDevice::CreateVertexBuffer()
	{
		/*
		* Create OpenGL vertex buffer
		*/
		OpenGLVertexBuffer* vertexBuffer = new OpenGLVertexBuffer();

		/*
		* Set target device for this device object
		*/
		SetDeviceObjectTargetDevice(vertexBuffer);

		return vertexBuffer;
	}
	ConstantBuffer* OpenGLGraphicsDevice::CreateConstantBuffer(const String& bufferName, unsigned int bufferSize)
	{
		/*
		* Create OpenGL constant buffer
		*/
		OpenGLConstantBuffer* constantBuffer = new OpenGLConstantBuffer(bufferName,bufferSize);
		constantBuffer->Initialize();

		/*
		* Set target device for this device object
		*/
		SetDeviceObjectTargetDevice(constantBuffer);

		return constantBuffer;
	}
	CommandBuffer* OpenGLGraphicsDevice::CreateCommandBuffer()
	{
		/*
		* Create OpenGL command buffer
		*/
		OpenGLCommandBuffer* commandBuffer = new OpenGLCommandBuffer();
		
		/*
		* Set target device for this device object
		*/
		SetDeviceObjectTargetDevice(commandBuffer);

		return commandBuffer;
	}
	Texture2D* OpenGLGraphicsDevice::CreateTexture2D()
	{
		/*
		* Create OpenGL texture2D
		*/
		OpenGLTexture2D* texture = new OpenGLTexture2D();

		/*
		* Set target device for this device object
		*/
		SetDeviceObjectTargetDevice(texture);

		return texture;
	}

	Shader* OpenGLGraphicsDevice::CreateShader(ShaderStage stage)
	{
		/*
		* Create OpenGL shader
		*/
		OpenGLShader* shader = new OpenGLShader(stage);

		/*
		* Set target device for this device object
		*/
		SetDeviceObjectTargetDevice(shader);

		return shader;
	}

	ShaderProgram* OpenGLGraphicsDevice::CreateShaderProgram()
	{
		/*
		* Create OpenGL shader
		*/
		OpenGLShaderProgram* shaderProgram = new OpenGLShaderProgram();

		/*
		* Set target device for this device object
		*/
		SetDeviceObjectTargetDevice(shaderProgram);

		return shaderProgram;
	}

}