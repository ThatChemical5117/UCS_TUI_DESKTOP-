#pragma once
#include<unordered_map>

#include <Interface/FactoryTemplate.h>

// Interface for an object that can Read and Write to a source
template<typename T>
class ReadWriteInterface
{
protected:
	FactoryTemplate<T>* m_factory; // Hold reference to singleton
public:
	ReadWriteInterface(FactoryTemplate<T>* factory) 
		: m_factory { factory }
	{};

	// Functions must be defined by the user
	virtual std::unordered_map<int, T> Read() = 0;
	virtual void Write(std::unordered_map<int, T>& input) = 0;

	virtual ~ReadWriteInterface() = default;
};
