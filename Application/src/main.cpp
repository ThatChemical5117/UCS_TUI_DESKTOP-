#include <iostream>
#include <limits>

// Required product repository
#include <Repository/ProductRepo.h>
#include <Factory/ProductFactory.h>
#include <Utils.h>


// Input methods
template <typename T>
T getInput() = delete;

template <>
int getInput()
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

template <>
std::string getInput()
{
	std::string userInput;

	getline(std::cin, userInput);

	return userInput;
};

template<>
ProductCatagory getInput()
{
	std::string userInput;
	getline(std::cin, userInput);

	return stringToProductCatagory(userInput);
};


// Temp function for testing
void AddProduct(ProductRepo& repo)
{
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

	do
	{
		Ultilities::DisplayMenu(); // Display the menu
		std::cin >> userInput; // get user input

		// Decide what to do
		switch (userInput)
		{
			case 1:
				Ultilities::ListProducts(repository.Get()); // List all products
				break;
			case 2:
				//ListOrders(orders);
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
