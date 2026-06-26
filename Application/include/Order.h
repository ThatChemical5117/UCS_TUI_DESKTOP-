#pragma once
#include <string>

// RECEIVED 
// PREPARING
// BUILDING
// TESTING
// READY
// SHIPPING
// FULFILLED

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

std::string_view orderStatusToString(OrderStatus status);
OrderStatus stringToOrderStatus(std::string_view str);

struct Order {
	int id;
	int productId;
	int stockNumber;

	std::string name;
	std::string email;
	std::string address;

	OrderStatus status;

	Order(int t_id, int t_productId, int t_stockNumber, std::string t_name, std::string t_email, std::string t_address, OrderStatus t_status);
	
};

std::ostream& operator<<(std::ostream& stream, Order order);
