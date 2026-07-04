#include <CSVLoadWriter.h>
#include <sstream>
#include <filesystem>

// Split a line using a delimiter
std::vector<std::string> splitWithDelimiter(const std::string& string, const char delimiter)
{
	// The line as a vector of strings
	std::vector<std::string> splitLine;
	std::stringstream stream(string); // string stream
	std::string substr; // substr

	while (getline(stream, substr, delimiter))
	{
		// Find non-white space
		if (substr.find_first_not_of(" \t\n\v\f\r") != std::string::npos && !substr.empty())
		{
			if (substr.find('\r') != std::string::npos) // delete while space
			{
				substr.erase(substr.find('\r'));
			}

			// Add substring to line
			splitLine.push_back(substr);
		}
	}

	// return the line as a split vector
	return splitLine;
};

// Check that the filename is valid
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
