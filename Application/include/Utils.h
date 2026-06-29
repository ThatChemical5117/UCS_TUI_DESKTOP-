#pragma once
#include <unordered_map>

#include <Product.h>
#include <Order.h>

namespace Ultilities
{
	void DisplayMenu();
	void ListProducts(const std::unordered_map<int, Product>& products);
	void ListOrders(const std::unordered_map<int, Order>& orders);
}
