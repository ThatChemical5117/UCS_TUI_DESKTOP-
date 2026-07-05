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
	std::cout << "- 7) Exit -" << std::endl;
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
ProductCatagory Utilities::getInput()
{
	return stringToProductCatagory(getInput<std::string>());
};

template<>
OrderStatus Utilities::getInput()
{
	return stringToOrderStatus(getInput<std::string>());
};

