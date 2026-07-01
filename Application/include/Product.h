#pragma once

#include <string>
#include <iostream>

enum ProductCatagory
{
	ENTRY,
	INTERMEDIATE,
	ADVANCED,
	ULTIMATE,
	CATEGORY_MAX
};

std::string_view ProductCatagoryToString(ProductCatagory cat);
ProductCatagory stringToProductCatagory(std::string_view str);


struct Product
{
	int id;
	std::string name;
	std::string description;
	std::string price;
	int stockCount;
	ProductCatagory category;

	Product(int t_id, std::string t_name, std::string t_description, std::string t_price, int t_stockCount, ProductCatagory t_category);
	Product();
};

std::ostream& operator<<(std::ostream& stream, const Product& product);


