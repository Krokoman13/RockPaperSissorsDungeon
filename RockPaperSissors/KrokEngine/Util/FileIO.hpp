#pragma once
#include <string>
#include <vector>

class FileIO
{
public:
	static const std::string ReadFile(const std::string& fullFilePath);
	static const std::vector<std::string> GetFileLines(const std::string& fullFilePath);
	static void WriteToFile(const std::string& fullFilePath, const std::string& text);
	static void WriteToFile(const std::string& fullFilePath, const std::vector<std::string>& text);
};

