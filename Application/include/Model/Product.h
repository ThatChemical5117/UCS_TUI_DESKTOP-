#pragma once

#include <string>
#include <iostream>

// Product category enum -- can only be in these categories
enum ProductCatagory
{
	ENTRY,
	INTERMEDIATE,
	ADVANCED,
	ULTIMATE,
	CATEGORY_MAX
};

// go from a Product Category enum to string and back
std::string_view ProductCatagoryToString(ProductCatagory cat);
ProductCatagory stringToProductCatagory(std::string_view str);


// Product definition
struct Product
{
	int id;
	std::string name;
	std::string description;
	std::string price;
	int stockCount;
	ProductCatagory category;

	// Default and explicit constructor
	Product(int t_id, std::string t_name, std::string t_description, std::string t_price, int t_stockCount, ProductCatagory t_category);
	Product();
};

// for printing
std::ostream& operator<<(std::ostream& stream, const Product& product);
