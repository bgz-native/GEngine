#include "OpenGLContext.h"

#include <glad/glad.h>
#include <glfw3.h>

namespace GEngine
{

OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	: m_windowHandle(windowHandle)
{
	//TODO Error Check here
}

void OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_windowHandle);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

void OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_windowHandle);
}


}



