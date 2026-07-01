#pragma once
#include <unordered_map>
#include <iostream>

#include <ReadWriteInterface.h>

template <typename T>
class RepositoryInterface
{
protected:
	ReadWriteInterface<T>* m_dataSourceInterface = nullptr;
	std::unordered_map<int, T> m_data;
public:
	RepositoryInterface(ReadWriteInterface<T>* interface)
		:m_dataSourceInterface { interface }
	{
		if (interface != nullptr)
			m_data = interface->Read();
		else 
			std::cout << "WARNING >> no valid Read-Write Interface available" << std::endl;
	};


	// Interface member functions
	virtual void Add(T&& item) = 0;
	//virtual std::optional<T> GetOne(int id) = 0;
	//virtual std::optional<T> Remove(int id) = 0;
	//virtual std::optional<T> Update(int id, T&& item) = 0;
	virtual std::unordered_map<int, T>& Get() = 0;

	virtual ~RepositoryInterface()
	{
		m_dataSourceInterface->Write(m_data);
		delete m_dataSourceInterface;
	}
};
