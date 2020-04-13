#include "Win64Window.h"



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

	m_property.m_title = property.m_title;
	m_property.m_width = property.m_width;
	m_property.m_height = property.m_height;

	m_glfwWindow = glfwCreateWindow((int)m_property.m_width,
		(int)m_property.m_height,
		m_property.m_title.c_str(),
		NULL, NULL);

	//TODO refactor
	glfwMakeContextCurrent(m_glfwWindow);

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

