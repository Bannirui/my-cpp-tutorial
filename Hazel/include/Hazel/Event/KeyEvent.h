//
// Created by dingrui on 25-6-22.
//

#pragma once

#include "Hazel/Event/Event.h"
#include "Hazel/Core/KeyCodes.h"

namespace Hazel
{
// 键盘事件
class KeyEvent : public Event
{
public:
    KeyCode GetKeyCode() const { return m_KeyCode; }

    EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
    KeyEvent(const KeyCode keycode): m_KeyCode(keycode) { }

    KeyCode m_KeyCode;
};

class KeyPressedEvent : public KeyEvent
{
public:
    KeyPressedEvent(const KeyCode keycode, int repeatCount): KeyEvent(keycode), m_RepeatCount(repeatCount) { }

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_RepeatCount << ")";
        return ss.str();
    }
    EVENT_CLASS_TYPE(KeyPressed)
private:
    int m_RepeatCount;
};

class KeyReleasedEvent : public KeyEvent
{
public:
    KeyReleasedEvent(const KeyCode keycode) : KeyEvent(keycode) { }

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << m_KeyCode;
        return ss.str();
    }

    EVENT_CLASS_TYPE(KeyReleased)
};

// 键盘输入
class KeyTypedEvent : public KeyEvent
{
public:
    KeyTypedEvent(const KeyCode keycode) : KeyEvent(keycode) { }

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyTypedEvent: " << m_KeyCode;
        return ss.str();
    }

    EVENT_CLASS_TYPE(KeyTyped)
};
}
