#pragma once

#include "GEngine/Renderer/Renderer.h"

struct GLFWwindow;

namespace GEngine
{

class OpenGLContext : public Renderer
{
public:
	OpenGLContext(GLFWwindow* windowHandle);

	virtual void Init() override;
	virtual void SwapBuffers() override;

private:
	GLFWwindow* m_windowHandle;


};

}
