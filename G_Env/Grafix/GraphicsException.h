#pragma once
#include "HrException.h"

class GraphicsException : public HrException
{
	public:
		GraphicsException(int line, const char* file, HRESULT hr);
		virtual const char* GetType() const noexcept override;
};

