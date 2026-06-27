#pragma once
#include<unordered_map>


template<typename T>
class ReadWriteInterface
{
public:
	ReadWriteInterface() = default;

	virtual std::unordered_map<int, T> Read() = 0;
	virtual void Write(std::unordered_map<int, T>& input) = 0;

	virtual ~ReadWriteInterface() = default;
};
