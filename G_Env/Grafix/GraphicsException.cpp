#include "GraphicsException.h"

GraphicsException::GraphicsException(int line, const char * file, HRESULT hr)
	:
	HrException(line, file, hr)
{}

const char * GraphicsException::GetType() const noexcept
{
	return "Graphics Exception";
}
