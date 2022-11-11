#include "StringUtil.hpp"

std::string StringUtil::Substring(const std::string& input, int remove_start, int remove_end)
{
	std::string outp;

	if (remove_start + remove_end >= (int)input.size())
	{
		return "";
	}

	for (int i = remove_start; i < ((int)input.size() - remove_end); i++)
	{
		outp += input[i];
	}

	return outp;
}

std::string StringUtil::SubstringEnd(const std::string& input, int remove_end)
{
	return Substring(input, 0, remove_end);
}

std::string StringUtil::SubstringStart(const std::string& input, int remove_start)
{
	return Substring(input, remove_start, 0);
}
