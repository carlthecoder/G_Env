#pragma once
#include <tuple>

class MouseEvent
{
	public:
		enum class Type
		{
			LPress,
			LRelease,
			RPress,
			RRelease,
			WheelUp,
			WheelDown,
			Move,
			Enter,
			Leave,
			Invalid,
		};	

	public:
		MouseEvent() noexcept;

		MouseEvent(MouseEvent::Type type, const int x, const int y, const bool leftIsPressed, const bool rightIsPressed) noexcept;

		bool IsValid() const noexcept;

		MouseEvent::Type GetType() const noexcept;

		std::pair<int, int> GetPosition() const noexcept;

		int GetPosX() const noexcept;

		int GetPosY() const noexcept;

		bool LeftIsPressed() const noexcept;

		bool RightIsPressed() const noexcept;

	private:
		MouseEvent::Type _type;
		bool _leftIsPressed;
		bool _rightIsPressed;
		int _x;
		int _y;
};