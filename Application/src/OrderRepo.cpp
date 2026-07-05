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

/*
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

Order OrderRepo::GetOne(int id)
{
	try{
		Order order = m_data.at(id);
		return order;
	} catch (const std::out_of_range& e)
	{
		std::cout << "No Order with id: " << id << std::endl;
		return {};
	};
};

Order OrderRepo::Remove(int id)
{
	Order orderToDelete = GetOne(id);
	if (orderToDelete.id != -1)
		m_data.erase(id);

	return orderToDelete;
};


std::unordered_map<int, Order>& OrderRepo::Get()
{
	return m_data;
};
*/

OrderRepo::~OrderRepo()
{
	m_dataSourceInterface->Write(m_data);
}
