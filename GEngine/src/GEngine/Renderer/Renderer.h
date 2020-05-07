#pragma once

namespace GEngine
{

class Renderer
{
public:
	virtual void Init() = 0;
	virtual void SwapBuffers() = 0;

};

}