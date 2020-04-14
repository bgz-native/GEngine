#include "Win64Window.h"

#include "GEngine/Events/ApplicationEvent.h"
#include "GEngine/Events/MouseEvent.h"
#include "GEngine/Events/KeyEvent.h"

namespace GEngine
{

Window* Window::Create(const WindowProperty& property)
{
	return new Win64Window(property);
}


Win64Window::Win64Window(const WindowProperty& property)
{
	Start(property);
}

Win64Window::~Win64Window()
{
	Destroy();
}

void Win64Window::Start(const WindowProperty& property)
{
	glfwInit();

	//TODO check if glfw is success exit 1 if not
	//glfw Error Callback

	m_property.m_title = property.m_title;
	m_property.m_width = property.m_width;
	m_property.m_height = property.m_height;

	m_glfwWindow = glfwCreateWindow((int)m_property.m_width,
		(int)m_property.m_height,
		m_property.m_title.c_str(),
		NULL, NULL);

	//TODO refactor
	glfwMakeContextCurrent(m_glfwWindow);

	glfwSetWindowUserPointer(m_glfwWindow, &m_property);


	glfwSetWindowCloseCallback(m_glfwWindow, [](GLFWwindow* window)
	{
		Win64WindowProperty& property = *(Win64WindowProperty*)glfwGetWindowUserPointer(window);

		WindowCloseEvent closeEvent;
		property.m_eventCallback(closeEvent);
	});

	glfwSetWindowSizeCallback(m_glfwWindow, [](GLFWwindow* window, int width, int height)
	{
		Win64WindowProperty& property = *(Win64WindowProperty*)glfwGetWindowUserPointer(window);

		property.m_width = width;
		property.m_height = height;

		WindowResizeEvent resizeEvent(width, height);
		property.m_eventCallback(resizeEvent);
	});


	glfwSetKeyCallback(m_glfwWindow, [](GLFWwindow* window, int key, int scanCode, int action, int mods)
	{
		Win64WindowProperty& property = *(Win64WindowProperty*)glfwGetWindowUserPointer(window);

		switch(action)
		{
			case GLFW_PRESS:
			{
				KeyPressedEvent keyEvent(key, 0);
				property.m_eventCallback(keyEvent);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent keyEvent(key);
				property.m_eventCallback(keyEvent);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent keyEvent(key, 1);
				property.m_eventCallback(keyEvent);
				break;
			}
		}
	});

	glfwSetMouseButtonCallback(m_glfwWindow, [](GLFWwindow* window, int button, int action, int mods)
	{
		Win64WindowProperty& property = *(Win64WindowProperty*)glfwGetWindowUserPointer(window);
		switch (action)
		{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent mouseEvent(button);
				property.m_eventCallback(mouseEvent);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent mouseEvent(button);
				property.m_eventCallback(mouseEvent);
				break;
			}

		}
	});

	glfwSetCursorPosCallback(m_glfwWindow, [](GLFWwindow* window, double xPos, double yPos)
	{
		Win64WindowProperty& property = *(Win64WindowProperty*)glfwGetWindowUserPointer(window);

		MouseMovedEvent mouseEvent((float)xPos, (float)yPos);
		property.m_eventCallback(mouseEvent);
	});


}


void Win64Window::Update()
{
	//TEST ONLY, please remove
	glClearColor(1, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(m_glfwWindow);

	glfwPollEvents();

}


void Win64Window::Destroy()
{
	glfwTerminate();
}

}

