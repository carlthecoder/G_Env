#pragma once
#include <bitset>
#include <queue>
#include "KeyEvent.h"

class Keyboard
{
	friend class GameWindow;	

	public:
		Keyboard() = default;
		Keyboard(const Keyboard&) = delete;
		const Keyboard& operator=(const Keyboard&) = delete;

		bool IsKeyDown(unsigned char keyCode) const noexcept;
		KeyEvent ReadKeyEvent() noexcept;		
		char ReadChar() noexcept;

		void Flush() noexcept;
		void FlushKey() noexcept;
		void FlushChar() noexcept;

		void EnableAutoRepeat() noexcept;
		void DisableAutoRepeat() noexcept;
		bool AutoRepeatIsEnabled() const noexcept;

	private:
		static constexpr unsigned int bufferSize = 16u;
		std::bitset<256u> _keyStates;
		std::queue<KeyEvent> _keyEvents;
		std::queue<char> _charbuffer;
		bool _autoRepeatEnabled = false;

		void OnKeyDownMessageReceived(unsigned char keyCode) noexcept;
		void OnKeyUpMessageReceived(unsigned char keyCode) noexcept;
		void OnCharMessageReceived(char keyCode) noexcept;
		void ClearState() noexcept;

		template<typename T>
		static void TrimBuffer(std::queue<T>& buffer);
};