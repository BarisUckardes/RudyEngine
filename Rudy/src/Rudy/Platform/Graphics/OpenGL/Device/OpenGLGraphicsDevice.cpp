#include "OpenGLGraphicsDevice.h"
#include <Rudy/Windowing/Window.h>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <Rudy/Platform/Graphics/OpenGL/Buffer/OpenGLIndexBuffer.h>
namespace Rudy
{
	OpenGLGraphicsDevice::OpenGLGraphicsDevice(Window* targetWindow) : GraphicsDevice(targetWindow)
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
		return new OpenGLIndexBuffer(this);
	}
	VertexBuffer* OpenGLGraphicsDevice::CreateVertexBuffer()
	{
		return nullptr;
	}
	CommandBuffer* OpenGLGraphicsDevice::CreateCommandBuffer()
	{
		return nullptr;
	}
	Texture2D* OpenGLGraphicsDevice::CreateTexture2D(unsigned int width, unsigned int height,
		TextureFormat format, TextureInternalFormat internalFormat, TextureDataType dataType,
		TextureMinFilter minFilter, TextureMagFilter magFilter,
		TextureWrapMode wrapModeS, TextureWrapMode wrapModeT,
		bool createMipmaps)
	{

		return nullptr;
	}
}