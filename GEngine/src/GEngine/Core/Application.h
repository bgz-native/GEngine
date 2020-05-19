#pragma once

#include "Core.h"
#include "Window.h"
#include "GEngine/Events/Event.h"
#include "GEngine/Events/ApplicationEvent.h"
#include "GEngine/Renderer/Shader.h"
#include "GEngine/Renderer/Buffer.h"

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

	unsigned int m_vertexArray;

	VertexBuffer* m_vertexBuffer;
	IndexBuffer* m_indexBuffer;


	Shader* m_shader;

};

}


