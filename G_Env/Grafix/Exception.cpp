#include "Exception.h"


Exception::Exception(int line, const char* file)
	: 
	lineNr(line),
	file(file)
{}

char const * Exception::what() const noexcept
{
	std::ostringstream oss;

	oss << "|Exception| " << std::endl
		<< "File: " << file << std::endl
		<< "Line: " << std::dec << lineNr << std::endl;
	
	whatBuffer = oss.str();

	return whatBuffer.c_str();
}

const char* Exception::GetType() const noexcept
{
	return "Exception";
}