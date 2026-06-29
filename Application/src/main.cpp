#include <iostream>

#include <ProductRepo.h>
#include <Utils.h>

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
				std::cout << "Not implemented\n";
				break;
			case 4:
				std::cout << "Not implemented\n";
				break;
		}

	} while (userInput != 5);
}
