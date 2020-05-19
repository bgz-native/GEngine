#include "Buffer.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace GEngine
{


VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
{
	switch (Renderer::GetAPI())
	{
		case RendererAPI::None: LOGE("Renderer API not set"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
	}

	LOGE("Unknown Error in Graphics Buffer");

	return nullptr;
}

IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
{
	switch (Renderer::GetAPI())
	{
		case RendererAPI::None: LOGE("Renderer API not set"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, size);
	}

	LOGE("Unknown Error in Graphics Buffer");

	return nullptr;
}

}

