#include <Factory/OrderFactory.h>
#include <sstream>

OrderFactory* OrderFactory::m_instance = nullptr;

OrderFactory* OrderFactory::GetInstance()
{
	if (m_instance == nullptr)
		return new OrderFactory;

	return m_instance;
};

Order OrderFactory::MakeItem(const std::vector<std::string>& line)
{
	if (line.size() < 7 )
		return {};

	int id = std::stoi(line.at(0));

	return { id, std::stoi(line.at(1)), std::stoi(line.at(2)), line.at(3), line.at(4), line.at(5), stringToOrderStatus(line.at(6)) };
}

std::string OrderFactory::MakeString(const Order& order)
{
	std::stringstream stream;
	stream << order.id << "," << order.productId << "," << order.stockNumber << "," << order.name << "," << order.email << "," << order.address << "," << orderStatusToString(order.status);
	
	return stream.str();
}


Order OrderFactory::MakeItem(int id, int productId, int stock, std::string name, std::string email, std::string address, OrderStatus status)
{
	return { id, productId, stock, name, email, address, status };
};

