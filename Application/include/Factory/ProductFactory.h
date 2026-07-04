#pragma once

#include <Interface/TemplateFactory.h> // Use the template interface class
#include <Model/Product.h>

// concrete class implements a Product template factory
class ProductFactory: public TemplateFactory<Product>
{
private:
	static ProductFactory* m_instance; // singleton instance
	ProductFactory() = default;
public:
	
	// return a product factory
	static ProductFactory* GetInstance();

	// Override provided functions to create items and strings
	Product MakeItem(const std::vector<std::string>& strings) override final;
	std::string MakeString(const Product& product) override final;

	// Overload of the MakeItem function
	Product MakeItem(int id, std::string name, std::string description, std::string price, int stockCounter, ProductCatagory category);

	// default destructor
	~ProductFactory() = default;
};



