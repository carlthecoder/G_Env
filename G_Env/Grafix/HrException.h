#pragma once
#include "Exception.h"

#include "Windows.h"

class HrException : public Exception
{
	public:
		HrException(int line, const char* file);
		HrException(int line, const char* file, HRESULT hr);
		~HrException() = default;

		virtual char const* what() const noexcept override;
		virtual const char* GetType() const noexcept override;

	protected:
		HRESULT hrCode;

		std::string TranslateErrorCode(HRESULT hr) const noexcept;
};