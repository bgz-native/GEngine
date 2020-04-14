#pragma once

#include "Core.h"
#include "Window.h"
#include "GEngine/Events/Event.h"
#include "GEngine/Events/ApplicationEvent.h"


namespace GEngine
{

class GENGINE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();
	void OnEvent(Event& onEvent);

private:
	bool OnWindowClose(WindowCloseEvent& event);


	Window* m_window;
	bool m_isRunning = false;


};

}


