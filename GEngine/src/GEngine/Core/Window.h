#pragma once

#include "Core.h"

namespace GEngine
{

struct WindowProperty
{
	std::string  m_title;
	unsigned int m_width;
	unsigned int m_height;

	WindowProperty(const std::string& title = "My Game",
				   unsigned int width		= 800,
				   unsigned int height		= 600) 
		: m_title(title), m_width(width), m_height(height)
	{
	}

};

class GENGINE_API Window
{
public:
	virtual ~Window() {}

	virtual void Update() = 0;

	virtual unsigned int GetWidth() const = 0;
	virtual unsigned int GetHeight() const = 0;

	static Window* Create();


};

}


