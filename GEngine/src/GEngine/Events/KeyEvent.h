#pragma once

#include "Event.h"

namespace GEngine
{

class GENGINE_API KeyEvent : public Event
{
public:
	inline int GetKeyCode() const { return m_keyCode; }

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
	KeyEvent(int keyCode) : m_keyCode(keyCode) {}

	int m_keyCode;

};

class GENGINE_API KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(int keyCode, int repeatCount)
		: KeyEvent(keyCode), m_repeatCount(repeatCount) {}

	inline int GetRepeatCount() const { return m_repeatCount; }

	EVENT_CLASS_TYPE(KeyPressed)

private:
	int m_repeatCount;
};

class GENGINE_API KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(int keyCode)
		: KeyEvent(keyCode) {}

	EVENT_CLASS_TYPE(KeyPressed)

};

}

