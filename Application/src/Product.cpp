#include <Model/Product.h>
#include <iostream>

// string representation of product category
const std::string Product::categoryStrings[static_cast<int>(Product::Category::CATEGORY_MAX)] = { "entry", "intermediate","advanced", "ultimate" };

// Product constructor
Product::Product(int id, std::string name, std::string description, std::string price, int stockCount, Product::Category category)
	: m_id { id }, m_name { name }, m_description { description }, m_price { price }, m_stockCount { stockCount }, m_category { category }
{
}

// Product default constructor (Null - invalid object)
Product::Product()
	:m_id { -1 }, m_name {""}, m_description {""}, m_price {"0.00"}, m_stockCount {-1}, m_category{ Product::Category::CATEGORY_MAX }
{};

std::string_view Product::CategoryToString(Product::Category category)
{
	return categoryStrings[static_cast<int>(category)];
};

// convert string to product category enum
Product::Category Product::CategoryFromString(std::string str)
{
	for (unsigned int i = 0; i < static_cast<int>(Category::CATEGORY_MAX); i++)
	{
		if (str.compare(categoryStrings[i]) == 0)
			return static_cast<Category>(i);
	}

	return Product::Category::CATEGORY_MAX; // return this as the error value
}


// Mutators 
int Product::getId() const { return m_id; };		
std::string Product::getName() const { return m_name; };
std::string Product::getDescription() const { return m_description; };
std::string Product::getPrice() const { return m_price; };
int Product::getStockCount() const { return m_stockCount; }
Product::Category Product::getCategory() const { return m_category; };

void Product::setId(int id) { m_id = id;};
void Product::setName(std::string name) { m_name = name; };
void Product::setDescription(std::string description) { m_description = description; };
void Product::setPrice(std::string price) { m_price = price; };
void Product::setStockCount(Category category) { m_category = category; };

// Print a product
std::ostream& operator<<(std::ostream& stream, const Product& product)
{
	stream << product.getId() << "\n";
	stream << product.getName() << "\n\t";
	stream << product.getPrice() << "\n\t";
	stream << product.getDescription() << "\n\t";
	stream << Product::CategoryToString(product.getCategory()) << " level\n\t";

	return stream;
}
