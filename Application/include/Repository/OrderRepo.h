#pragma once
#include <string>

#include <Model/Order.h>
#include <Interface/RepositoryInterface.h>

class OrderRepo: public RepositoryInterface<Order>
{
private:
public:
	OrderRepo();

	OrderRepo(std::string str);

	OrderRepo(ReadWriteInterface<Order>* interface);

	//void Add(Order&& item) override final;
	//Order GetOne(int id) override final;
	//Order Remove(int id) override final;
	//std::unordered_map<int, Order>& Get() override final;

	~OrderRepo();
};
