#pragma once

#include "Core.h"
#include "GEngine/Events/Event.h"

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
	using EventCallbackFn = std::function<void(Event&)>;

	Window() {}
	virtual ~Window() = default;

	virtual void Update() = 0;

	virtual unsigned int GetWidth() const = 0;
	virtual unsigned int GetHeight() const = 0;

	virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

	static Window* Create(const WindowProperty& property = WindowProperty());


};

}


