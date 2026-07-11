#include <iostream>

#include <Interface/Application.h>

// Required product repository
#include <Interface/RepositoryInterface.h>
#include <CSVLoadWriter.h>
#include <Factory/ProductFactory.h>
#include <Factory/OrderFactory.h>
#include <Utils.h>

// Main
int main()
{
	// User input variable
	int userInput; 
	CSVLoadWriter<Product>* writer= new CSVLoadWriter<Product>{ "Products.csv", ProductFactory::GetInstance() };
	RepositoryInterface<Product> productRepository = { writer };

	CSVLoadWriter<Order>* owriter = new CSVLoadWriter<Order> { "Orders.csv", OrderFactory::GetInstance() };
	RepositoryInterface<Order> orderRepository { owriter };

	do
	{
		Utilities::DisplayMenu(); // Display the menu
		std::cin >> userInput; // get user input

		// Decide what to do
		switch (userInput)
		{
			case 1:
				Utilities::ListProducts(productRepository.Get()); // List all products
				break;
			case 2:
				Utilities::ListOrders(orderRepository.Get());
				break;
			case 3:
				Utilities::AddProduct(productRepository);// Add product
				break;
			case 4:
				Utilities::AddOrder(orderRepository); // Add order
				break;
			case 5:
				Utilities::Remove<Product>(productRepository, "Product"); // Add product
				break;
			case 6:
				Utilities::Remove<Order>(orderRepository, "Order"); // remove order
				break;
			case 7:
				Utilities::UpdateProduct(productRepository);
				break;
			case 8:
				Utilities::UpdateOrder(orderRepository);
				break;
		}

	} while (userInput != 9);

	writer->Write(productRepository.Get());
	owriter->Write(orderRepository.Get());
}

