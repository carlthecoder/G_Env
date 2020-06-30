#include "Keyboard.h"

bool Keyboard::IsKeyDown(unsigned char keyCode) const noexcept
{
	return _keyStates[keyCode];
}

KeyEvent Keyboard::ReadKeyEvent() noexcept
{
	if (_keyEvents.size() > 0u)
	{
		auto event = _keyEvents.front();
		_keyEvents.pop();
		return event;
	}
	else
	{
		return KeyEvent();
	}
}

char Keyboard::ReadChar() noexcept
{
	if (_charbuffer.size() > 0u)
	{
		unsigned char charcode = _charbuffer.front();
		_charbuffer.pop();
		return charcode;
	}
	return 0;
}

void Keyboard::Flush() noexcept
{
	FlushKey();
	FlushChar();
}

void Keyboard::FlushKey() noexcept
{
	_keyEvents = std::queue<KeyEvent>();
}

void Keyboard::FlushChar() noexcept
{
	_charbuffer = std::queue<char>();
}

void Keyboard::EnableAutoRepeat() noexcept
{
	_autoRepeatEnabled = true;
}

void Keyboard::DisableAutoRepeat() noexcept
{
	_autoRepeatEnabled = false;
}

bool Keyboard::AutoRepeatIsEnabled() const noexcept
{
	return _autoRepeatEnabled;
}

// Private methods called by the window class in response to window messages from Windows
void Keyboard::OnKeyDownMessageReceived(unsigned char keyCode) noexcept
{
	_keyStates[keyCode] = true;
	_keyEvents.push(KeyEvent(KeyEvent::Type::Press, keyCode));
	TrimBuffer(_keyEvents);
}

void Keyboard::OnKeyUpMessageReceived(unsigned char keyCode) noexcept
{
	_keyStates[keyCode] = false;
	_keyEvents.push(KeyEvent(KeyEvent::Type::Release, keyCode));
	TrimBuffer(_keyEvents);
}

void Keyboard::OnCharMessageReceived(char keyCode) noexcept
{
	_charbuffer.push(keyCode);
	TrimBuffer(_charbuffer);
}

void Keyboard::ClearState() noexcept
{
	_keyStates.reset();
}

template<typename T>
void Keyboard::TrimBuffer(std::queue<T>& buffer)
{
	while (buffer.size() > bufferSize)
	{
		buffer.pop();
	}
}