#include "Application.h"

namespace GEngine
{

Application::Application()
{
	m_window = Window::Create();
	m_isRunning = true;
}

Application::~Application()
{
}

void Application::Run()
{
	while (m_isRunning)
	{
		m_window->Update();
	}
}

}


