#include "Renderer.h"

namespace GEngine
{

void Renderer::BeginScene()
{

}

void Renderer::EndScene()
{

}

void Renderer::Submit(const VertexArray* va)
{
	va->Bind();
	RenderCommand::DrawElements(va);
}

}

