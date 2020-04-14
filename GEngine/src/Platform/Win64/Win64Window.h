#pragma once

#include "GEngine/Core/Window.h"
#include "glfw3.h"

namespace GEngine
{

class Win64Window : public Window
{
public:
	Win64Window(const WindowProperty& property);
	virtual ~Win64Window();

	void Update() override;
	
	inline unsigned int GetWidth() const override { return m_property.m_width; }
	inline unsigned int GetHeight() const override { return m_property.m_height; }

	inline void SetEventCallback(const EventCallbackFn& callback) override { m_property.m_eventCallback = callback; }

private:
	virtual void Start(const WindowProperty& property);
	virtual void Destroy();

	GLFWwindow* m_glfwWindow;

private:
	struct Win64WindowProperty
	{
		std::string m_title;
		unsigned int m_width;
		unsigned int m_height;

		EventCallbackFn m_eventCallback;
	};

	Win64WindowProperty m_property;

};


}


