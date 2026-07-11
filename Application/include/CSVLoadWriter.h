#pragma once
#include <Interface/ReadWriteInterface.h> // Utilize this interface

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

// functions not part of the template class implementation
std::vector<std::string> splitWithDelimiter(const std::string& string, const char delimiter);
bool validateFile(std::string_view filename);

// template class can be used with any type from a CSV
// As long as the user gives a factory that can format the type correctly from the csv line
template <typename T>
class CSVLoadWriter: public ReadWriteInterface<T>
{
private:
	std::string m_filename;
	bool isValid = false;
public:

	// Constructor fills in file name and factory
	CSVLoadWriter(const std::string& filename, 
			FactoryTemplate<T>* factory)
		:  ReadWriteInterface<T>(factory), m_filename { filename }
	{
		// Check if the file is valid at construction
		if (!validateFile(m_filename))
			std::cout << "Invalid file: (" << m_filename << ")" << std::endl;
		else
			isValid = true;
	};

	CSVLoadWriter() {};

	// Overloaded Read - takes in data from a CSV
	std::unordered_map<int, T> Read() override final
	{
		// return structure
		std::unordered_map<int, T> storage;

		if (!isValid) // check if the rechecks passed - don't do anything if not
			return storage;

		// open a input file stream
		std::ifstream inputFile(m_filename);

		if (!inputFile.is_open()) // Validate the stream works
		{
			std::cout << "Failed to open file: " << m_filename << std::endl;
			return storage;
		}

		// store line
		std::string line;
		while(getline(inputFile, line)) // get file contents
		{
			// Split the line into it's items
			std::vector<std::string> arguments = splitWithDelimiter(line, ',');

			// Use factory to create a object
			T result = ReadWriteInterface<T>::m_factory->MakeItem(arguments);
			
			// put the value into the storage
			if (result.getId() != -1)
			{
				storage.emplace(result.getId(), result); // use emplace 
			}
		}

		// Move the storage object to outside the function (copy)
		return storage;
	};

	// Write the CSV
	void Write(std::unordered_map<int, T>& input) override final
	{
		if (!isValid) // check that the pre-check passed
		{
			std::cout << "No valid file" << std::endl;
			return;
		}

		// Open the file -- erase it's contents
		std::ofstream outputFile(m_filename, std::ofstream::trunc);

		// if the file can't be opened
		if (!outputFile.is_open()) 
		{
			std::cout << "Cannot open file" << std::endl;
			return;
		}
	
		// Loop through the input data structure, use the factory to create valid lines
		for (const auto& [key, item]: input)
		{
			outputFile << ReadWriteInterface<T>::m_factory->MakeString(item) << "\n";// place line into output
		};
	};


	void setSrc(std::string str) override final
	{
		m_filename = str;
		isValid = validateFile(m_filename);
	};

	void setFactory(FactoryTemplate<T>* factory) override final
	{
		ReadWriteInterface<T>::m_factory = factory;
	};

};
