#pragma once

#include "VertexArray.h"

namespace GEngine
{

class RendererAPI
{
public:
	enum class API
	{
		None = 0,
		OpenGL = 1,
		DirectX = 2,
		Vulkan = 3
	};
public:
	virtual void SetClearColor(float r, float g, float b, float a) = 0;
	virtual void Clear() = 0;

	virtual void DrawElements(const VertexArray* va) = 0;

	inline static API GetAPI() { return s_api; }

private:
	static API s_api;
};


}