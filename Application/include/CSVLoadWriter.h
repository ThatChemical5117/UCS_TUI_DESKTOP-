#pragma once
#include <ReadWriteInterface.h>

#include <fstream>
#include <utility>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <optional>

std::vector<std::string> splitWithDelimiter(const std::string& string, const char delimiter);
bool validateFile(std::string_view filename);

template <typename T>
class CSVLoadWriter: public ReadWriteInterface<T>
{
private:
	std::string m_filename;
	std::function<std::optional<std::pair<int, T>> (std::vector<std::string>&)> m_lineParser;
	std::function<std::string (const T&)> m_itemParser;
	bool isValid = false;
public:

	CSVLoadWriter(const std::string& filename, 
			std::function<std::optional<std::pair<int, T>> (std::vector<std::string>&)> lineParser,
			std::function<std::string (const T&)> itemParser)
		: m_filename { filename },
		  m_lineParser { lineParser },
		  m_itemParser { itemParser }
	{
		if (!validateFile(m_filename))
			std::cout << "Invalid file: (" << m_filename << ")" << std::endl;
		else
			isValid = true;
	};

	std::unordered_map<int, T> Read() 
	{
		std::unordered_map<int, T> storage;

		if (!isValid)
			return storage;

		std::ifstream inputFile(m_filename);

		if (!inputFile.is_open())
		{
			std::cout << "Failed to open file: " << m_filename << std::endl;
			return storage;
		}

		std::string line;
		while(getline(inputFile, line))
		{
			// Get the result from the user defined function
			std::vector<std::string> arguments = splitWithDelimiter(line, ',');
			std::optional<std::pair<int, T>> result = m_lineParser(arguments);

			// put the value into the storage
			if (result.has_value())
			{
				storage.emplace(result.value());
			}
		}

		// Move the storage object to outside the function
		return storage;
	};

	void Write(std::unordered_map<int, T>& input)
	{
		if (!isValid) 
		{
			std::cout << "No valid file" << std::endl;
			return;
		}

		// Open the file -- erase it's contents
		std::ofstream outputFile(m_filename, std::ofstream::trunc);

		if (!outputFile.is_open()) 
		{
			std::cout << "Cannot open file" << std::endl;
			return;
		}
	
		for (const auto& [key, item]: input)
		{
			outputFile << m_itemParser(item) << "\n";
		};
	};
};
