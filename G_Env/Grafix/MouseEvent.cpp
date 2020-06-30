#include "MouseEvent.h"

MouseEvent::MouseEvent() noexcept
	:
	_type(MouseEvent::Type::Invalid),
	_leftIsPressed(false),
	_rightIsPressed(false),
	_x(0),
	_y(0)
{}


MouseEvent::MouseEvent(MouseEvent::Type type, const int x, const int y, const bool leftIsPressed, const bool rightIsPressed) noexcept
	:
	_type(type),
	_leftIsPressed(leftIsPressed),
	_rightIsPressed(rightIsPressed),
	_x(x),
	_y(y)
{}

bool MouseEvent::IsValid() const noexcept
{
	return _type != Type::Invalid;
}

MouseEvent::Type MouseEvent::GetType() const noexcept
{
	return _type;
}

std::pair<int, int> MouseEvent::GetPosition() const noexcept
{
	return { _x, _y };
}

int MouseEvent::GetPosX() const noexcept
{
	return _x;
}

int MouseEvent::GetPosY() const noexcept
{
	return _y;
}

bool MouseEvent::LeftIsPressed() const noexcept
{
	return _leftIsPressed;
}

bool MouseEvent::RightIsPressed() const noexcept
{
	return _rightIsPressed;
}