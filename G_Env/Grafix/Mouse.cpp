#include "Mouse.h"

std::pair<int, int> Mouse::GetPosition() const noexcept
{
	return { _x, _y };
}

int Mouse::GetPosX() const noexcept
{
	return _x;
}

int Mouse::GetPosY() const noexcept
{
	return _y;
}

bool Mouse::LeftIsPressed() const noexcept
{
	return _leftIsPressed;
}

bool Mouse::RightIsPressed() const noexcept
{
	return _rightIsPressed;
}

bool Mouse::IsInWindow() const noexcept
{
	return _isInWindow;
}

MouseEvent Mouse::Read() noexcept
{
	if (_buffer.size() > 0u)
	{
		MouseEvent e = _buffer.front();
		_buffer.pop();
		return e;
	}

	return MouseEvent();
}

void Mouse::Flush()
{
	_buffer = std::queue<MouseEvent>();
}

void Mouse::OnMouseMove(int newX, int newY) noexcept
{
	_x = newX;
	_y = newY;

	_buffer.push(MouseEvent(MouseEvent::Type::Move, this->GetPosX(), this->GetPosY(), this->LeftIsPressed(), this->RightIsPressed()));
	TrimBuffer();
}

void Mouse::OnMouseLeave() noexcept
{
	_isInWindow = false;
	_buffer.push(MouseEvent(MouseEvent::Type::Leave, this->GetPosX(), this->GetPosY(), this->LeftIsPressed(), this->RightIsPressed()));
	TrimBuffer();
}

void Mouse::OnMouseEnter() noexcept
{
	_isInWindow = true;
	_buffer.push(MouseEvent(MouseEvent::Type::Enter, this->GetPosX(), this->GetPosY(), this->LeftIsPressed(), this->RightIsPressed()));
	TrimBuffer();
}

void Mouse::OnLeftPressed(int x, int y) noexcept
{
	_leftIsPressed = true;
	_buffer.push(MouseEvent(MouseEvent::Type::LPress, this->GetPosX(), this->GetPosY(), this->LeftIsPressed(), this->RightIsPressed()));
	TrimBuffer();
}

void Mouse::OnLeftReleased(int x, int y) noexcept
{
	_leftIsPressed = false;
	_buffer.push(MouseEvent(MouseEvent::Type::LRelease, this->GetPosX(), this->GetPosY(), this->LeftIsPressed(), this->RightIsPressed()));
	TrimBuffer();
}

void Mouse::OnRightPressed(int x, int y) noexcept
{
	_rightIsPressed = true;
	_buffer.push(MouseEvent(MouseEvent::Type::RPress, this->GetPosX(), this->GetPosY(), this->LeftIsPressed(), this->RightIsPressed()));
	TrimBuffer();
}

void Mouse::OnRightReleased(int x, int y) noexcept
{
	_rightIsPressed = false;
	_buffer.push(MouseEvent(MouseEvent::Type::RRelease, this->GetPosX(), this->GetPosY(), this->LeftIsPressed(), this->RightIsPressed()));
	TrimBuffer();
}

void Mouse::OnWheelUp(int x, int y) noexcept
{
	_buffer.push(MouseEvent(MouseEvent::Type::WheelUp, this->GetPosX(), this->GetPosY(), this->LeftIsPressed(), this->RightIsPressed()));
	TrimBuffer();
}

void Mouse::OnWheelDown(int x, int y) noexcept
{
	_buffer.push(MouseEvent(MouseEvent::Type::WheelDown, this->GetPosX(), this->GetPosY(), this->LeftIsPressed(), this->RightIsPressed()));
	TrimBuffer();
}

void Mouse::TrimBuffer() noexcept
{
	while (_buffer.size() > bufferSize)
	{
		_buffer.pop();
	}
}

void Mouse::OnWheelDelta(int x, int y, int delta) noexcept
{
	_wheelDeltaCarry += delta;

	while (_wheelDeltaCarry >= wheel_delta)
	{
		_wheelDeltaCarry -= wheel_delta;
		OnWheelUp(x, y);
	}

	while (_wheelDeltaCarry <= -wheel_delta)
	{
		_wheelDeltaCarry += wheel_delta;
		OnWheelDown(x, y);
	}
}