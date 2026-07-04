#pragma once
#include <string>


enum class OrderStatus {
	RECEIVED,
	RREPARING,
	BUILDING,
	TESTING,
	READY,
	SHIPPING,
	FULFILLED,
	STATUS_MAX
};

// Converter functions
std::string_view orderStatusToString(OrderStatus status);
OrderStatus stringToOrderStatus(std::string_view str);

// Order object representations
struct Order {
	int id;
	int productId;
	int stockNumber;

	std::string name;
	std::string email;
	std::string address;

	OrderStatus status;

	// Constructor
	Order(int t_id, int t_productId, int t_stockNumber, std::string t_name, std::string t_email, std::string t_address, OrderStatus t_status);
	Order();
};

// overload << to print
std::ostream& operator<<(std::ostream& stream, Order order);
