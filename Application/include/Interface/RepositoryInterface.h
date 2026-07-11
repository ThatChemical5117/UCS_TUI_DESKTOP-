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
			std::cout << "WARNING >> no valid Read-Write Interface available" << std::endl;
	};


	// Interface member functions
	virtual void Add(T&& item) // Allows for child classes to override if necessary
	{
		try {
			m_data.at(item.getId());
		} catch (const std::out_of_range& e)
		{
			m_data.emplace(item.getId(), item);
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

		if (item.getId() != -1)
			m_data.erase(id);

		return item;
	};

	virtual std::unordered_map<int, T>& Get()
	{
		return m_data;
	};


	// Pure virtual function
	virtual T Update(T&& item)
	{
		T existingItem = GetOne(item.getId());
		if (existingItem.getId() == -1 || existingItem == item)
			return {};

		m_data.at(item.getId()) = item;
		return existingItem;
	}

	// Destroy the data source interface
	virtual ~RepositoryInterface()
	{
		// Free the pointer
		m_dataSourceInterface->Write();
		delete m_dataSourceInterface;
	}
};
