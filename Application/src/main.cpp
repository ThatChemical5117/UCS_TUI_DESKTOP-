#include <iostream>

// Required product repository
#include <Repository/ProductRepo.h>
#include <Repository/OrderRepo.h>
#include <Factory/ProductFactory.h>
#include <Factory/OrderFactory.h>
#include <Utils.h>

// Temp function for testing
void AddProduct(ProductRepo& repo)
{
	using namespace Utilities;
	// Product strings
	const static std::string productCategoryStrings [static_cast<int>(ProductCatagory::CATEGORY_MAX)] = { "entry", "intermediate","advanced", "ultimate" };
	std::cout << "Enter product id (int)" << std::endl;
	int id = getInput<int>();

	std::cout << "Enter product name (string)" << std::endl;
	std::string name = getInput<std::string>();

	std::cout << "Enter product description (string - no spaces)" << std::endl;
	std::string desc = getInput<std::string>();

	std::cout << "Enter product price (double)" << std::endl;
	std::string price = getInput<std::string>();

	std::cout << "Enter product stock count (int)" << std::endl;
	int count = getInput<int>();
	
	std::cout << "Enter product category (see existing)" << std::endl;
	for (std::string str: productCategoryStrings)
	{
		std::cout << str << " ";
	};
	std::cout << std::endl;

	ProductCatagory cat = getInput<ProductCatagory>();

	repo.Add(ProductFactory::GetInstance()->MakeItem(id, name, desc, price, count, cat));
};

void AddOrder(OrderRepo& repo)
{
	using namespace Utilities;
	const static std::string orderStatusStrings [static_cast<int>(OrderStatus::STATUS_MAX)] = {};

	std::cout << "Enter order id (int)" << std::endl;
	int id = getInput<int>();
	std::cout << "Enter product id (int)" << std::endl;
	int productId = getInput<int>();
	std::cout << "Enter stock # (int)" << std::endl;
	int stockNumber = getInput<int>();
	std::cout << "Enter name" << std::endl;
	std::string name = getInput<std::string>();
	std::cout << "Enter email" << std::endl;
	std::string email = getInput<std::string>();
	std::cout << "Enter address" << std::endl;
	std::string address = getInput<std::string>();
	std::cout << "Enter order status (preparing, shipping, ready)" << std::endl;
	OrderStatus status = getInput<OrderStatus>();
	

	repo.Add(OrderFactory::GetInstance()->MakeItem(id, productId, stockNumber, name, email, address, status));

};

template <typename T>
void Remove(RepositoryInterface<T>& repo, std::string_view itemName)
{
	std::cout << "Enter id of " << itemName << " to remove" << std::endl;
	int id = Utilities::getInput<int>();

	repo.Remove(id);
};

// Main
int main()
{
	// User input variable
	int userInput; 
	ProductRepo repository; // Product repo
	OrderRepo orders;

	do
	{
		Utilities::DisplayMenu(); // Display the menu
		std::cin >> userInput; // get user input

		// Decide what to do
		switch (userInput)
		{
			case 1:
				Utilities::ListProducts(repository.Get()); // List all products
				break;
			case 2:
				Utilities::ListOrders(orders.Get());
				break;
			case 3:
				AddProduct(repository);// Add product
				break;
			case 4:
				AddOrder(orders); // Add order
				break;
			case 5:
				Remove<Product>(repository, "Product");
				break;
			case 6:
				Remove<Order>(orders, "Order");
				break;
		}

	} while (userInput != 7);
}
