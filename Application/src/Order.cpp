#include <Model/Order.h>
#include <ostream>
#include <iostream>

// String representations of the order status enum
const static std::string orderStatusStrings [static_cast<int>(OrderStatus::STATUS_MAX)] =
	{"received", "preparing", "building", "testing", "ready", "shipped", "fulfilled" };	


// convert an order status to a string
std::string_view orderStatusToString(OrderStatus status)
{
	if (status == OrderStatus::STATUS_MAX)
		return "INVALID_STATUS";

	return orderStatusStrings[static_cast<int>(status)];
}

// convert a string to an order status
OrderStatus stringToOrderStatus(std::string_view str)
{
	for (unsigned int i = 0; i < static_cast<int>(OrderStatus::STATUS_MAX); i++)
	{

		std::cout << str << std::endl;
		if (str.compare(orderStatusStrings[i]) == 0)
		{
			return static_cast<OrderStatus>(i);
		}
	}

	return OrderStatus::STATUS_MAX;
};


// Construct a Order
Order::Order(int t_id, int t_productId, int t_stockNumber, std::string t_name, std::string t_email, std::string t_address, OrderStatus t_status)
	: id { t_id }, productId { t_productId }, stockNumber { t_stockNumber }, name { t_name }, email { t_email }, address { t_address }, status { t_status }
{}

// Print an order status
std::ostream& operator<<(std::ostream& stream, OrderStatus status)
{
	stream << orderStatusToString(status);
	return stream;
};


// Print an order
std::ostream& operator<<(std::ostream& stream, Order order)
{
	stream << order.id << std::endl;
	stream << order.productId << std::endl;
	stream << order.stockNumber << std::endl;
	stream << order.name << std::endl;
	stream << order.email << std::endl;
	stream << order.address << std::endl;
	stream << order.status;

	return stream;
}
