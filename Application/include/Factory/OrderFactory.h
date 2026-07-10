#pragma once

#include <Interface/FactoryTemplate.h>
#include <Model/Order.h>

class OrderFactory: public FactoryTemplate<Order>
{
private:
	static OrderFactory* m_instance; // singleton instance
	OrderFactory() = default;

public:

	// Instance access function
	static OrderFactory* GetInstance();

	Order MakeItem(const std::vector<std::string>& strings) override final;
	std::string MakeString(const Order& order) override final;

	~OrderFactory() = default;
};

