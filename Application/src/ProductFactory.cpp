#include <Factory/ProductFactory.h>
#include <sstream>

// Set static variable to nullptr
ProductFactory* ProductFactory::m_instance = nullptr;

// Get singleton instance
ProductFactory* ProductFactory::GetInstance()
{
	// Create new instance if one is not already available
	if (m_instance == nullptr)
		m_instance = new ProductFactory;

	return m_instance;
}

// Factory method to make an Item (Product) from a line (From csv)
Product ProductFactory::MakeItem(const std::vector<std::string>& line)
{
	if (line.size() < 6)
		return {};

	int key = std::stoi(line.at(0));

	return { key, line[1], line[2], line[3], std::stoi(line[4]), stringToProductCatagory(line[5]) };
};

// Factory method to make a string from an item (Product)
std::string ProductFactory::MakeString(const Product& product)
{
	std::stringstream stream;
	stream << product.id << "," << product.name << "," << product.description << "," << product.price << "," << product.stockCount << "," << ProductCatagoryToString(product.category);

	return stream.str();
};

// Factory method overload to make an item from explicit variables
Product ProductFactory::MakeItem(int id, std::string name, std::string description, std::string price, int stockCounter, ProductCatagory category)
{
	return { id, name, description, price, stockCounter, category };
};
