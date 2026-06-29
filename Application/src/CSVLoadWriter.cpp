#include <CSVLoadWriter.h>
#include <sstream>
#include <filesystem>

std::vector<std::string> splitWithDelimiter(const std::string& string, const char delimiter)
{
	std::vector<std::string> splitLine;
	std::stringstream stream(string);
	std::string substr;

	while (getline(stream, substr, delimiter))
	{
		if (substr.find_first_not_of(" \t\n\v\f\r") != std::string::npos && !substr.empty())
		{
			if (substr.find('\r') != std::string::npos)
			{
				substr.erase(substr.find('\r'));
			}

			splitLine.push_back(substr);
		}
	}

	return splitLine;

};

bool validateFile(std::string_view filename)
{
	std::filesystem::path path = std::filesystem::current_path();

	path.append(filename);

	// TODO: Replace with logging system later
	if (!std::filesystem::exists(path)) {
		std::cout << "Can not open: " << filename << "\nCannot find" << std::endl;
		return false;
	} 

	if (std::filesystem::is_directory(path))
	{
		std::cout << "Can not open: " << filename << "\nis not a file" << std::endl;
		return false;
	}

	if (path.extension() != ".csv")
	{
		std::cout << "Invalid file format: " << path.extension()  << std::endl;	
		std::cout << "Expected .csv" << std::endl;
		return false;
	};

	return true;

}
