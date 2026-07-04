#pragma once
#include <unordered_map>
#include <iostream>

#include <Interface/ReadWriteInterface.h>

// Template class for manipulating a data source
// Uses a Read-Write interface to read data in and write data out - allows a user to define concrete classes that take in from different data sources
template <typename T>
class RepositoryInterface
{
protected:
	ReadWriteInterface<T>* m_dataSourceInterface = nullptr; 
	std::unordered_map<int, T> m_data;
public:
	// Constructor - The desired interface is provided by the caller
	// the pointer is managed by the Repository Interface 
	RepositoryInterface(ReadWriteInterface<T>* interface)
		:m_dataSourceInterface { interface }
	{
		if (interface != nullptr)
			m_data = interface->Read();
		else 
			std::cout << "WARNING >> no valid Read-Write or Template Factory Interface available" << std::endl;
	};


	// Interface member functions
	virtual void Add(T&& item) = 0;
	//virtual std::optional<T> GetOne(int id) = 0;
	//virtual std::optional<T> Remove(int id) = 0;
	//virtual std::optional<T> Update(int id, T&& item) = 0;
	virtual std::unordered_map<int, T>& Get() = 0;

	// Destroy the data source interface
	virtual ~RepositoryInterface()
	{
		// Free the pointer
		delete m_dataSourceInterface;
	}
};
