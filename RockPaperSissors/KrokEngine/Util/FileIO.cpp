#include "FileIO.hpp"
#include <fstream>

const std::string FileIO::ReadFile(const std::string& fullFilePath)
{
	std::vector<std::string> lines = GetFileLines(fullFilePath);
	std::string fullText;

	for (std::string line : lines)
	{
		fullText += line + '\n';
	}

	return fullText;
}

const std::vector<std::string> FileIO::GetFileLines(const std::string& fullFilePath)
{
	std::vector<std::string> lines;

	std::ifstream ifs(fullFilePath);

	if (!ifs.bad())
	{
		std::string currentLine;

		while (std::getline(ifs, currentLine))
		{
			lines.push_back(currentLine);
		}

		ifs.close();
	}

	return lines;
}

void FileIO::WriteToFile(const std::string& fullFilePath, const std::string& text)
{
	std::ofstream ofs(fullFilePath);

	if (!ofs.bad())
	{
		ofs << text;
		ofs.close();
	}
}

void FileIO::WriteToFile(const std::string& fullFilePath, const std::vector<std::string>& textLines)
{
	std::string fullText;

	for (std::string line : textLines)
	{
		fullText += line + '\n';
	}

	WriteToFile(fullFilePath, fullText);
}
