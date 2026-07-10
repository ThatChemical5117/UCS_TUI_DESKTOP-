#include "Model/Order.h"
#include "Model/Product.h"
#include <Utils.h>
#include <limits>
#include <string>
#include <cmath>


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
double Utilities::getInput()
{
	double userDouble;
	std::cin >> userDouble;

	while(!std::cin)
	{
		std::cout << "Invalid input\nPlease enter an integer value\n";

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	return std::trunc(userDouble * 100) / 100;
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
	std::string price { std::to_string(getInput<double>())};

	std::cout << "Enter product stock count (int)" << std::endl;
	int count { getInput<int>() };

	std::cout << "Enter product category (see existing)" << std::endl;
	printProductCategoryValues();
	Product::Category cat = getInput<Product::Category>();

	repo.Add({id, name, desc, price, count, cat});
};

void Utilities::AddOrder(RepositoryInterface<Order>& repo)
{
	std::cout << "Enter order id (int)" << std::endl;
	int id = getInput<int>();

	std::cout << "Enter product id (int)" << std::endl;
	int proudctId = getInput<int>();

	std::cout << "Enter stock number (int)" << std::endl;
	int stockNumber = getInput<int>();

	std::cout << "Enter name" << std::endl;
	std::string name = getInput<std::string>();

	std::cout << "Enter email" << std::endl;
	std::string email = getInput<std::string>();

	std::cout << "Enter address" << std::endl;
	std::string address = getInput<std::string>();

	std::cout << "Enter order status" << std::endl;
	PrintOrderStatusValues();
	Order::Status status = getInput<Order::Status>();
	
	repo.Add({ id, proudctId, stockNumber, name, email, address, status });
};

