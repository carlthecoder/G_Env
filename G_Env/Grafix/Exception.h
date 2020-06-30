#pragma once

#include <exception>
#include <string>
#include <sstream>

class Exception : protected std::exception
{
	public:
		Exception(int line, const char* file);
		~Exception() = default; 

		virtual const char* what() const noexcept override;
		virtual const char* GetType() const noexcept;

	protected:
		int lineNr;
		std::string file;
		mutable std::string whatBuffer;
};

