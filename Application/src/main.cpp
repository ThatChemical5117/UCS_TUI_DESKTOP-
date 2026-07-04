#include <iostream>

// Required product repository
#include <Repository/ProductRepo.h>
#include <Repository/OrderRepo.h>
#include <Factory/ProductFactory.h>
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
				std::cout << "Not implemented\n";
				break;
			case 4:
				AddProduct(repository); // Add product
				break;
		}

	} while (userInput != 5);
}
