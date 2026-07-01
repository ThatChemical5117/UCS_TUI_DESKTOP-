#include <iostream>

#include <ProductRepo.h>
#include <Utils.h>

void AddProduct(ProductRepo& repo)
{
	const static std::string productCategoryStrings [static_cast<int>(ProductCatagory::CATEGORY_MAX)] = { "entry", "intermediate","advanced", "ultimate" };

	std::cout << "Enter an item then press enter" << std::endl;

	Product product;

	std::cout << "Enter product id (int)" << std::endl;
	std::cin >> product.id;

	std::cout << "Enter product name (string)" << std::endl;
	std::cin >> product.name;

	std::cout << "Enter product description (string - no spaces)" << std::endl;
	std::cin >> product.description;

	std::cout << "Enter product price (double)" << std::endl;
	std::cin >> product.price;

	std::cout << "Enter product stock count (int)" << std::endl;
	std::cin >> product.stockCount;
	
	std::cout << "Enter product category (see existing)" << std::endl;
	for (std::string str: productCategoryStrings)
	{
		std::cout << str << " ";
	};
	std::cout << std::endl;
	std::string productCat;
	std::cin >> productCat;

	product.category = stringToProductCatagory(productCat);

	repo.Add(std::move(product));
};


int main()
{
	int userInput;
	ProductRepo repository;

	do
	{
		Ultilities::DisplayMenu();
		std::cin >> userInput;

		switch (userInput)
		{
			case 1:
				Ultilities::ListProducts(repository.Get());
				break;
			case 2:
				//ListOrders(orders);
				break;
			case 3:
				AddProduct(repository);
				break;
			case 4:
				std::cout << "Not implemented\n";
				break;
		}

	} while (userInput != 5);
}
