#include "Application.h"

namespace GEngine
{

Application::Application()
{
	m_isRunning = true;
	m_window = Window::Create();
	m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
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

void Application::OnEvent(Event& onEvent)
{
	//LOGD("%s%s", e.GetName(), "\n");

	EventDispatcher dispatcher(onEvent);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
}

bool Application::OnWindowClose(WindowCloseEvent& event)
{
	m_isRunning = false;
	return true;
}

}


