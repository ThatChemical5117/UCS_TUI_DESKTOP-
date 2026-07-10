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

	return { id, std::stoi(line.at(1)), std::stoi(line.at(2)), line.at(3), line.at(4), line.at(5), Order::StatusFromString(line.at(6)) };
}

std::string OrderFactory::MakeString(const Order& order)
{
	std::stringstream stream;
	stream << order.getId() << "," 
		<< order.getProductId() << "," 
		<< order.getStockNumber() << "," 
		<< order.getName() << "," 
		<< order.getEmail() << "," << order.getAddress() << "," << Order::StatusToString(order.getStatus());
	
	return stream.str();
}
