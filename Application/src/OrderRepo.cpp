#include <Repository/OrderRepo.h>
#include <Factory/OrderFactory.h>
#include <CSVLoadWriter.h>

OrderRepo::OrderRepo()
	:OrderRepo { "Orders.csv" }
{};

OrderRepo::OrderRepo(std::string str)
	:OrderRepo { new CSVLoadWriter<Order> { str, OrderFactory::GetInstance() } }
{};

OrderRepo::OrderRepo(ReadWriteInterface<Order>* interface)
	: RepositoryInterface { interface }
{};

void OrderRepo::Add(Order&& item) 
{
	try
	{
		m_data.at(item.id);
	} catch (const std::out_of_range& e)
	{
		m_data.emplace(item.id, item);
	};
};

std::unordered_map<int, Order>& OrderRepo::Get()
{
	return m_data;
};

OrderRepo::~OrderRepo()
{
	m_dataSourceInterface->Write(m_data);
}
