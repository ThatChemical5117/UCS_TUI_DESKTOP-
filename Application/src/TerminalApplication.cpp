#include <Impl/TerminalApplication.h>
#include <CSVLoadWriter.h>
#include <Factory/ProductFactory.h>
#include <Factory/OrderFactory.h>
#include <Utils.h>

TerminalApplication::TerminalApplication()
	:m_productRepo { new CSVLoadWriter<Product>("Products.csv", ProductFactory::GetInstance()) },
	 m_orderRepo { new CSVLoadWriter<Order>("Orders.csv", OrderFactory::GetInstance()) }
{
}

void TerminalApplication::Start()
{
	int userInput;
	
	do {
		Utilities::DisplayMenu();
		userInput = Utilities::getInput<int>();

		switch(userInput)
		{
			case 1:
				Utilities::ListProducts(m_productRepo.Get()); // List all products
				break;
			case 2:
				Utilities::ListOrders(m_orderRepo.Get());
				break;
			case 3:
				Utilities::AddProduct(m_productRepo);// Add product
				break;
			case 4:
				Utilities::AddOrder(m_orderRepo); // Add order
				break;
			case 5:
				Utilities::Remove<Product>(m_productRepo, "Product"); // Add product
				break;
			case 6:
				Utilities::Remove<Order>(m_orderRepo, "Order"); // remove order
				break;
			case 7:
				Utilities::UpdateProduct(m_productRepo);
				break;
			case 8:
				Utilities::UpdateOrder(m_orderRepo);
				break;
		};

	} while(true);
};


TerminalApplication::~TerminalApplication()
{};
