#pragma once

#include "Core.h"
#include "Window.h"

namespace GEngine
{

class GENGINE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();

private:
	Window* m_window;
	bool m_isRunning = false;


};

}


