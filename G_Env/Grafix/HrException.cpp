#include "HrException.h"

HrException::HrException(int line, const char * file)
	:
	Exception(line, file),
	hrCode(GetLastError())
{}

HrException::HrException(int line, const char * file, HRESULT hr)
	:
	Exception(line, file),
	hrCode(hr)
{}

char const * HrException::what() const noexcept
{
	std::ostringstream oss;

	oss << "|" << GetType() << "| " << std::endl
		<< "Code: " << hrCode << std::endl
		<< "CodeHex: " << std::hex << hrCode << std::endl
		<< " File: " << file << " | Line: " << std::dec << lineNr << std::endl
		<< "Description: " << TranslateErrorCode(hrCode) << std::endl;

	whatBuffer = oss.str();

	return whatBuffer.c_str();
}

const char* HrException::GetType() const noexcept
{
	return "HR Exception";
}

std::string HrException::TranslateErrorCode(HRESULT hr) const noexcept
{
	char* pBuffer = nullptr;

	DWORD nBufferLen = FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		nullptr, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		reinterpret_cast<LPSTR>(&pBuffer), 0, nullptr);

	if (nBufferLen == 0)
	{
		return "Unidentified Error Code.";
	}

	std::string errorString = pBuffer;
	LocalFree(pBuffer);
	return errorString;
}