#include "Application.h"

#include <glad/glad.h>

namespace GEngine
{

Application::Application()
{
	m_isRunning = true;
	m_window = Window::Create();
	m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

	glGenVertexArrays(1, &m_vertexArray);
	glBindVertexArray(m_vertexArray);

	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3 * sizeof(float)), nullptr);

	glGenBuffers(1, &m_indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);

	unsigned int indices[3] = { 0, 1, 2 };
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

Application::~Application()
{

}

void Application::Run()
{
	while (m_isRunning)
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(m_vertexArray);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

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


