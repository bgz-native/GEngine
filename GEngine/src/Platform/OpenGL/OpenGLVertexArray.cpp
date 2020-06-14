#include "OpenGLVertexArray.h"

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

OpenGLVertexArray::OpenGLVertexArray()
{
	glGenVertexArrays(1, &m_rendererId);
}

void OpenGLVertexArray::Bind() const
{
	glBindVertexArray(m_rendererId);
}

void OpenGLVertexArray::UnBind() const
{
	glBindVertexArray(0);
}

void OpenGLVertexArray::AddVertexBuffer(const VertexBuffer* vertexBuffer)
{
	glBindVertexArray(m_rendererId);
	vertexBuffer->Bind();

	uint32_t index = 0;
	for (const auto& element : vertexBuffer->GetLayout())
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, element.GetElementCount(),
			DataTypeToOpenGLBaseType(element.type), element.normalized ? GL_TRUE : GL_FALSE,
			vertexBuffer->GetLayout().GetStride(), (const void*)element.offset);
		index++;
	}

	m_vertexBuffers.push_back(vertexBuffer);
}

void OpenGLVertexArray::SetIndexBuffer(const IndexBuffer* indexBuffer)
{
	glBindVertexArray(m_rendererId);
	indexBuffer->Bind();

	m_indexBuffer = indexBuffer;
}

}