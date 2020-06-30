#include "KeyEvent.h"

KeyEvent::KeyEvent()
	:
	eventType(Type::Invalid),
	code(0u)
{}

KeyEvent::KeyEvent(Type type, unsigned char code)
	:
	eventType(type),
	code(code)
{}

bool KeyEvent::IsPress() const noexcept
{
	return eventType == Type::Press;

}

bool KeyEvent::IsRelease() const noexcept
{
	return eventType == Type::Release;
}

bool KeyEvent::IsValid() const noexcept
{
	return eventType != Type::Invalid;
}

unsigned char KeyEvent::GetCode() const noexcept
{
	return code;
}
