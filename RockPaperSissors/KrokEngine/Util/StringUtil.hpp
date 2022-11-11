#pragma once
#include <string>

class StringUtil
{
public:
	static std::string Substring(const std::string& input, int remove_start, int remove_end);
	static std::string SubstringEnd(const std::string& input, int remove_end);
	static std::string SubstringStart(const std::string& input, int remove_start);
};

