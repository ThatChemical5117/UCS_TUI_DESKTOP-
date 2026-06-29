#include "Utils.h"


void Ultilities::DisplayMenu()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "- 1) List Product - " << std::endl;
	std::cout << "- 2) List Orders - " << std::endl;
	std::cout << "- 3) Change Product values - " << std::endl;
	std::cout << "- 4) Add new Product - " << std::endl;
	std::cout << "- 5) Exit -" << std::endl;
	std::cout << "----------------------" << std::endl;
};

void Ultilities::ListProducts(const std::unordered_map<int, Product>& products)
{
	for (const auto& [key, product]: products)
	{
		std::cout << product << std::endl;
	}
};

void Ultilities::ListOrders(const std::unordered_map<int, Order>& orders)
{
	for (const auto& [key, order]: orders)
	{
		std::cout << order << std::endl;
	}
};

