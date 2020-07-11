#pragma once

#include "RendererAPI.h"

namespace GEngine
{

class RenderCommand
{
public:
	inline static void SetClearColor(float r, float g, float b, float a)
	{
		s_rendererApi->SetClearColor(r, g, b, a);
	}

	inline static void Clear()
	{
		s_rendererApi->Clear();
	}

	inline static void DrawElements(const VertexArray* va)
	{
		s_rendererApi->DrawElements(va);
	}

private:
	static RendererAPI* s_rendererApi;

};

}