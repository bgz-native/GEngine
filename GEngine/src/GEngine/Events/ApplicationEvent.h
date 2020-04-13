#pragma once

#include "Event.h"

namespace GEngine
{

class GENGINE_API WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() {}

	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	EVENT_CLASS_TYPE(WindowClose)
};

class GENGINE_API WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(unsigned int newWidth, unsigned int newHeight)
		: m_newWidth(newWidth), m_newHeight(newHeight) {}

	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	EVENT_CLASS_TYPE(WindowResize)

private:
	unsigned int m_newWidth;
	unsigned int m_newHeight;
};



}