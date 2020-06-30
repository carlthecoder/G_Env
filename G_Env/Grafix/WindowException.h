#pragma once
#include "HrException.h"

class WindowException : public HrException
{
	public:
		WindowException(int line, const char* file);

		virtual const char* GetType() const noexcept override;
};