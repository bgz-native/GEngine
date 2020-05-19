#pragma once

namespace GEngine
{

class Context
{
public:
	virtual void Init() = 0;
	virtual void SwapBuffers() = 0;

};

}