#pragma once
#include <unordered_map>

#include <Model/Product.h>
#include <Model/Order.h>

// functions that don't belong to another class
namespace Ultilities
{
	void DisplayMenu();
	void ListProducts(const std::unordered_map<int, Product>& products);
	void ListOrders(const std::unordered_map<int, Order>& orders);
}
