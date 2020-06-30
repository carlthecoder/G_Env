#pragma once
#include "MouseEvent.h"
#include <queue>

class Mouse
{
	friend class GameWindow;
	friend class MouseEvent;

	public:
		Mouse() = default;
		Mouse(const Mouse&) = delete;
		Mouse& operator=(const Mouse&) = delete;

		std::pair<int, int> GetPosition() const noexcept;
		int GetPosX() const noexcept;
		int GetPosY() const noexcept;
		bool LeftIsPressed() const noexcept;
		bool RightIsPressed() const noexcept;
		bool IsInWindow() const noexcept;
		MouseEvent Read() noexcept;
		void Flush();

	private:
		static constexpr unsigned int bufferSize = 16u;
		static constexpr int wheel_delta = 120;
		int _x;
		int _y;
		int _wheelDeltaCarry;
		bool _isInWindow = false;
		bool _leftIsPressed = false;
		bool _rightIsPressed = false;
		std::queue<MouseEvent> _buffer;

		void OnMouseMove(int newX, int newY) noexcept;
		void OnMouseLeave() noexcept;
		void OnMouseEnter() noexcept;
		void OnLeftPressed(int x, int y) noexcept;
		void OnLeftReleased(int x, int y) noexcept;
		void OnRightPressed(int x, int y) noexcept;
		void OnRightReleased(int x, int y) noexcept;
		void OnWheelUp(int x, int y) noexcept;
		void OnWheelDown(int x, int y) noexcept;
		void TrimBuffer() noexcept;
		void OnWheelDelta(int x, int y, int delta) noexcept;
};