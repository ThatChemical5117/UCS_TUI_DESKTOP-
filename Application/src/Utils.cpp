#include "Model/Order.h"
#include "Model/Product.h"
#include <Utils.h>
#include <limits>
#include <string>

// Display
void Utilities::DisplayMenu()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "- 1) List Product - " << std::endl;
	std::cout << "- 2) List Orders - " << std::endl;
	std::cout << "- 3) Add new Product - " << std::endl;
	std::cout << "- 4) Add new Order - " << std::endl;
	std::cout << "- 5) Remove Product -" << std::endl;
	std::cout << "- 6) Remove Order -" << std::endl;
	std::cout << "- 7) Update Product -" << std::endl;
	std::cout << "- 8) Update Order -" << std::endl;
	std::cout << "- 9) Exit -" << std::endl;
	std::cout << "----------------------" << std::endl;
};

// List products
void Utilities::ListProducts(const std::unordered_map<int, Product>& products)
{
	for (const auto& [key, product]: products)
	{
		std::cout << product << std::endl;
	}
};

// List orders
void Utilities::ListOrders(const std::unordered_map<int, Order>& orders)
{
	for (const auto& [key, order]: orders)
	{
		std::cout << order << std::endl;
	}
};


template <>
int Utilities::getInput()
{
	int userInt;
	std::cin >> userInt;
	 
	while(!std::cin)
	{
		std::cout << "Invalid input\nPlease enter an integer value\n";

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return userInt;
};

template<>
std::string Utilities::getInput()
{
	std::string userInput;
	getline(std::cin, userInput);

	return userInput;
};


template<>
Product::Category Utilities::getInput()
{
	return Product::CategoryFromString(getInput<std::string>());
};

template<>
Order::Status Utilities::getInput()
{
	return Order::StatusFromString(getInput<std::string>());
};


void printProductCategoryValues()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(Product::Category::CATEGORY_MAX); i++)
	{
		std::cout << Product::categoryStrings[i] << ", ";
	};
	std::cout << std::endl;

};

void PrintOrderStatusValues()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(Order::Status::STATUS_MAX); i++)
	{
		std::cout << Order::statusStrings[i] << ", ";
	};

	std::cout << std::endl;
}

void Utilities::AddProduct(RepositoryInterface<Product>& repo)
{
	std::cout << "Enter product id (int)" << std::endl;
	int id { getInput<int>() };

	std::cout << "Enter product name (string)" << std::endl;
	std::string name { getInput<std::string>() };

	std::cout << "Enter product description (string)" << std::endl;
	std::string desc { getInput<std::string>() };

	std::cout << "Enter product price (double)" << std::endl;
	std::string price { getInput<std::string>()};

	std::cout << "Enter product stock count (int)" << std::endl;
	int count { getInput<int>() };

	std::cout << "Enter product category (see existing)" << std::endl;
	printProductCategoryValues();
	Product::Category cat = getInput<Product::Category>();

	repo.Add({id, name, desc, price, count, cat});
};


void Utilities::UpdateProduct(RepositoryInterface<Product>& repo)
{
	std::cout << "enter id of product you want to update" << std::endl;		
	int id { Utilities::getInput<int>() };

	Product product = repo.GetOne(id);
	if (product.getId() == -1)
		return;	
	do
	{
		std::cout << "Enter number to change field (1-6) or -1 to  quit";
		int field = Utilities::getInput<int>();
		
		std::cout << "Enter new ";
		switch(field)
		{
			case 1:
				std::cout << "id (Previous: " << product.getId() << ")\n";
				product.setId(getInput<int>());
				break;
			case 2:
				std::cout << "name (Previous: \"" << product.getName() << "\")\n";
				product.setName(getInput<std::string>());
				break;
			case 3:
				std::cout << "description (Previous: \"" << product.getDescription() << "\")\n";
				product.setDescription(getInput<std::string>());
				break;
			case 4:
				std::cout << "price (Previous: \"" << product.getPrice() << "\")\n";
				product.setPrice(getInput<std::string>());
				break;
			case 5:
				std::cout << "count (Previous: " << product.getStockCount() << ")\n";
				break;
			case 6:
				std::cout << "category (Previous: " << Product::CategoryToString(product.getCategory()) << ")\n";
				std::cout << "Available options are:\n";
				printProductCategoryValues();
				product.setCategory(getInput<Product::Category>());
				break;
		};

		if (field == -1)
			break;
	} while (true);

	repo.Update(std::move(product));
};


void Utilities::AddOrder(RepositoryInterface<Order>& repo)
{
	std::cout << "Enter order id (int)" << std::endl;
	int id { getInput<int>() };

	std::cout << "Enter product id (int)" << std::endl;
	int proudctId { getInput<int>() };

	std::cout << "Enter stock number (int)" << std::endl;
	int stockNumber { getInput<int>() };

	std::cout << "Enter name" << std::endl;
	std::string name { getInput<std::string>() };

	std::cout << "Enter email" << std::endl;
	std::string email { getInput<std::string>() };

	std::cout << "Enter address" << std::endl;
	std::string address { getInput<std::string>() };

	std::cout << "Enter order status" << std::endl;
	PrintOrderStatusValues();
	Order::Status status { getInput<Order::Status>() };
	
	repo.Add({ id, proudctId, stockNumber, name, email, address, status });
};

void Utilities::UpdateOrder(RepositoryInterface<Order>& repo)
{
	std::cout << "Enter the id of the order you want to update" << std::endl;
	int id { getInput<int>() };
	
	Order order { repo.GetOne(id) };

	if (order.getId() == -1)
		return;

	do
	{
		std::cout << "Enter number (1-7) to edit a field or -1 to quit" << std::endl;
		int field { getInput<int>() };

		std::cout << "Enter new ";
		switch (field)
		{
			case 1:
				std::cout << "id (Previous: " << order.getId() << ")\n";
				order.setId(getInput<int>());
				break;
			case 2:
				std::cout << "product id (Previous: " << order.getProductId() << ")\n";
				order.setProductId(getInput<int>());
				break;
			case 3:
				std::cout << "stock number (Previous: " << order.getStockNumber() << ")\n";
				order.setStockNumber(getInput<int>());
				break;
			case 4:
				std::cout << "customer name (Previous: " << order.getName() << ")\n";
				order.setName(getInput<std::string>());
				break;
			case 5:
				std::cout << "customer email address (Previous: " << order.getEmail() << ")\n";
				order.setEmail(getInput<std::string>());
				break;
			case 6:
				std::cout << "customer shipping address (Previous: " << order.getAddress() << ")\n";
				order.setAddress(getInput<std::string>());
			case 7:
				std::cout << "order status (Previous: " << Order::StatusToString(order.getStatus()) << ")\n";
				std::cout << "Enter any of these values:\n";
				PrintOrderStatusValues();
				order.setStatus(getInput<Order::Status>());
				break;
		}

		if (field == -1)
			break;

	} while (true);
	
	repo.Update(std::move(order));
};


