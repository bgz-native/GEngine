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

	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};
	m_vertexBuffer = VertexBuffer::Create(vertices, sizeof(vertices));

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3 * sizeof(float)), nullptr);

	uint32_t indices[3] = { 0, 1, 2 };
	m_indexBuffer = IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));


	std::string vertexSource = R"(

		#version 330 core

		layout(location = 0) in vec3 a_Position;

		void main()
		{
			gl_Position = vec4(a_Position, 1.0);
		}

	)";

	std::string fragmentSource = R"(

		#version 330 core

		layout(location = 0) out vec4 color;

		void main()
		{
			color = vec4(0.8, 0.2, 0.3, 1.0);
		}

	)";


	m_shader = new Shader(vertexSource, fragmentSource);


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

		m_shader->Bind();

		glBindVertexArray(m_vertexArray);
		glDrawElements(GL_TRIANGLES, m_indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

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


