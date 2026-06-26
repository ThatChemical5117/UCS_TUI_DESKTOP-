#pragma once
#include <functional>
#include <string>
#include <vector>

class CSVLoader
{
private:
	std::vector<std::string> splitWithDelimiter(const std::string& string, const char delimiter);
	bool validateFile(std::string_view filename);
public:
	CSVLoader() = default;
	void load(const std::string& t_filename, std::function<void (std::vector<std::string>&)> t_lineParseFunc);
};
