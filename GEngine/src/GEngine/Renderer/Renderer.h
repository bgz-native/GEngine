#pragma once

#include "RenderCommand.h"

namespace GEngine
{

class Renderer 
{
public:
	static void BeginScene();
	static void EndScene();

	static void Submit(const VertexArray* va);

	inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

private:

};

}