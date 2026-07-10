#pragma once
#include <unordered_map>

#include <Model/Product.h>
#include <Model/Order.h>
#include <Interface/RepositoryInterface.h>

// functions that don't belong to another class
namespace Utilities
{
	void DisplayMenu();
	void ListProducts(const std::unordered_map<int, Product>& products);
	void ListOrders(const std::unordered_map<int, Order>& orders);
	
	// Input and template functions
	template <typename T>
	T getInput() = delete;

	template <>
	int getInput();

	template <>
	std::string getInput();

	template<>
	Product::Category getInput();

	template<>
	Order::Status getInput();

	void AddProduct(RepositoryInterface<Product>& repo);
	void AddOrder(RepositoryInterface<Order>& repo);

	void UpdateOrder(RepositoryInterface<Order>& repo);
	void UpdateProduct(RepositoryInterface<Product>& repo);

	template <typename T>
	void Remove(RepositoryInterface<T>& repo, std::string_view itemName)
	{
		std::cout << "Enter id of " << itemName << " to remove" << std::endl;
		int id = Utilities::getInput<int>();

		repo.Remove(id);
	}

}
