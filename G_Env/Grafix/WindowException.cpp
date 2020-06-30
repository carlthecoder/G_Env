#include "WindowException.h"

WindowException::WindowException(int line, const char* file)
	:
	HrException(line, file, GetLastError())
{}

const char* WindowException::GetType() const noexcept
{
	return "Window Exception";
}