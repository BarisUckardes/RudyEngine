#include "OpenGLGraphicsDevice.h"
#include <Rudy/Windowing/Window.h>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <Rudy/Platform/Graphics/OpenGL/Buffer/OpenGLIndexBuffer.h>
#include <Rudy/Platform/Graphics/OpenGL/Buffer/OpenGLVertexBuffer.h>
#include <Rudy/Platform/Graphics/OpenGL/Texture/OpenGLTexture2D.h>
#include <Rudy/Platform/Graphics/OpenGL/Command/OpenGLCommandBuffer.h>
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

}