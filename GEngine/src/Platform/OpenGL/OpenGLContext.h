#pragma once

#include "GEngine/Renderer/Context.h"

struct GLFWwindow;

namespace GEngine
{

class OpenGLContext : public Context
{
public:
	OpenGLContext(GLFWwindow* windowHandle);

	virtual void Init() override;
	virtual void SwapBuffers() override;

private:
	GLFWwindow* m_windowHandle;


};

}
