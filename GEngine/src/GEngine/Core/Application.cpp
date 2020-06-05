#include "Application.h"

#include <glad/glad.h>

namespace GEngine
{

static GLenum DataTypeToOpenGLBaseType(DataType type)
{
	switch (type)
	{
		case GEngine::DataType::Float: return GL_FLOAT;
		case GEngine::DataType::Float2: return GL_FLOAT;
		case GEngine::DataType::Float3: return GL_FLOAT;
		case GEngine::DataType::Float4: return GL_FLOAT;
		case GEngine::DataType::Mat3: return GL_FLOAT;
		case GEngine::DataType::Mat4: return GL_FLOAT;
		case GEngine::DataType::Int: return GL_INT;
		case GEngine::DataType::Int2: return GL_INT;
		case GEngine::DataType::Int3: return GL_INT;
		case GEngine::DataType::Int4: return GL_INT;
		case GEngine::DataType::Bool: return GL_BOOL;
	}

	return 0;

}

Application::Application()
{
	m_isRunning = true;
	m_window = Window::Create();
	m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

	glGenVertexArrays(1, &m_vertexArray);
	glBindVertexArray(m_vertexArray);

	float vertices[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		 0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
	};
	m_vertexBuffer = VertexBuffer::Create(vertices, sizeof(vertices));

	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3 * sizeof(float)), nullptr);

	{
		BufferLayout layout = {
			{ DataType::Float3, "a_Position" },
			{ DataType::Float4, "a_Color" }
		};

		m_vertexBuffer->SetLayout(layout);
	}


	uint32_t index = 0;
	for (const auto& element : m_vertexBuffer->GetLayout())
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, element.GetElementCount(),
			DataTypeToOpenGLBaseType(element.type), element.normalized ? GL_TRUE : GL_FALSE,
			m_vertexBuffer->GetLayout().GetStride(), (const void*)element.offset);
		index++;
	}

	uint32_t indices[3] = { 0, 1, 2 };
	m_indexBuffer = IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));

	std::string vertexSource = R"(

		#version 330 core

		layout(location = 0) in vec3 a_Position;
		layout(location = 1) in vec4 a_Color;

		out vec4 v_Color;

		void main()
		{
			v_Color = a_Color;
			gl_Position = vec4(a_Position, 1.0);
		}

	)";

	std::string fragmentSource = R"(

		#version 330 core

		layout(location = 0) out vec4 color;
		
		in vec4 v_Color;

		void main()
		{
			color = vec4(0.8, 0.2, 0.3, 1.0);
			color = v_Color;
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


