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
	virtual void Add(T&& item)
	{
		try {
			m_data.at(item.id);
		} catch (const std::out_of_range& e)
		{
			m_data.emplace(item.id, item);
		};
	};

	virtual T GetOne(int id)
	{
		try {
			T item = m_data.at(id);
			return item;
		} catch (const std::out_of_range& e)
		{
			std::cout << "No items with id: " << id << std::endl;
			return {};
		};
	};

	virtual T Remove(int id)
	{
		T item = GetOne(id);

		if (item.id != -1)
			m_data.erase(id);

		return item;
	};

	//virtual std::optional<T> Update(int id, T&& item) = 0;
	virtual std::unordered_map<int, T>& Get()
	{
		return m_data;
	};

	// Destroy the data source interface
	virtual ~RepositoryInterface()
	{
		// Free the pointer
		delete m_dataSourceInterface;
	}
};
