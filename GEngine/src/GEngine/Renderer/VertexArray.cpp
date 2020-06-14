#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"


namespace GEngine
{

VertexArray* VertexArray::Create()
{
	switch (Renderer::GetAPI())
	{
		case RendererAPI::None: LOGE("Renderer API not set"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexArray();
	}

	LOGE("Unknown Error in Graphics Buffer");

	return nullptr;
}

}