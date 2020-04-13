#pragma once

#include "Event.h"

namespace GEngine
{

class GENGINE_API MouseButtonEvent : public Event
{
public:
	inline int GetMouseButton() const { return m_mouseButton; }

	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

protected:
	MouseButtonEvent(int mouseButton)
		: m_mouseButton(mouseButton) {}

	int m_mouseButton;
};

class GENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(int mouseButton) :
		MouseButtonEvent(mouseButton) {}

	EVENT_CLASS_TYPE(MouseButtonPressed)

};


class GENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(int mouseButton) :
		MouseButtonEvent(mouseButton) {}

	EVENT_CLASS_TYPE(MouseButtonReleased)
};



class GENGINE_API MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(float x, float y) 
		:m_mouseX(x), m_mouseY(y) {}

	inline float GetX() const { return m_mouseX; }
	inline float GetY() const { return m_mouseY; }

	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	EVENT_CLASS_TYPE(MouseMoved)

private:
	float m_mouseX;
	float m_mouseY;
};




}