#pragma once

#include "GEngine/Renderer/RendererAPI.h"

namespace GEngine
{

class OpenGLRendererAPI : public RendererAPI
{
public:
	virtual void SetClearColor(float r, float g, float b, float a) override;
	virtual void Clear() override;
	virtual void DrawElements(const VertexArray* va)  override;
private:
};

}