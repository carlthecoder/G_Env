#pragma once
class KeyEvent
{
	public:
		enum class Type
		{
			Press,
			Release,
			Invalid
		};

	public:
		KeyEvent();		
		KeyEvent(Type type, unsigned char code);

		bool IsPress() const noexcept;

		bool IsRelease() const noexcept;

		bool IsValid() const noexcept;

		unsigned char GetCode() const noexcept;

	private:
		Type eventType;
		unsigned char code;
};