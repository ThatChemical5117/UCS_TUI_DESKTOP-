#include <Model/Order.h>
#include <ostream>
#include <iostream>

// String representations of the order status enum
const std::string Order::statusStrings [static_cast<int>(Order::Status::STATUS_MAX)] =
	{"received", "preparing", "building", "testing", "ready", "shipped", "fulfilled" };	


// convert an order status to a string
std::string_view Order::StatusToString(Status status)
{
	if (status == Status::STATUS_MAX)
		return "INVALID_STATUS";

	return statusStrings[static_cast<int>(status)];
}

// convert a string to an order status
Order::Status Order::StatusFromString(const std::string& str)
{
	for (unsigned int i = 0; i < static_cast<int>(Order::Status::STATUS_MAX); i++)
	{

		if (str.compare(statusStrings[i]) == 0)
		{
			return static_cast<Order::Status>(i);
		}
	}

	return Status::STATUS_MAX;
};


// Construct a Order
Order::Order(int id, int productId, int stockNumber, std::string name, std::string email, std::string address, Status status)
	: m_id { id }, m_productId { productId }, m_stockNumber { stockNumber }, m_name { name }, m_email { email }, m_address { address }, m_status { status }
{}

Order::Order()
	: m_id{ -1 }, m_productId { -1 }, m_stockNumber { -1 }, m_name { "" }, m_email { "" }, m_address { "" }, m_status { Status::STATUS_MAX }
{};


// Accessors
int Order::getId() const { return m_id; }
int Order::getProductId() const { return m_productId; }
int Order::getStockNumber() const { return m_stockNumber; }
std::string Order::getName() const { return m_name; }
std::string Order::getEmail() const { return m_email; }
std::string Order::getAddress() const { return m_address; }
Order::Status Order::getStatus() const { return m_status; }

// Mutators
void Order::setId(int id) { m_id = id; }
void Order::setProductId(int productId) { m_productId = productId; }
void Order::setStockNumber(int stockNumber) {  m_stockNumber = stockNumber; }
void Order::setName(std::string name) { m_name = name; }
void Order::setEmail(std::string email) { m_email = email; }
void Order::setAddress(std::string address) { m_address = address; }
void Order::setStatus(Status status) { m_status = status; }

// Print an order
std::ostream& operator<<(std::ostream& stream, const Order& order)
{
	stream << order.getId() << std::endl;
	stream << order.getProductId() << "\n\t";
	stream << order.getStockNumber() << "\n\t";
	stream << order.getName() << "\n\t";
	stream << order.getEmail() << "\n\t";
	stream << order.getAddress() << "\n\t";
	stream << Order::StatusToString(order.getStatus());

	return stream;
}
