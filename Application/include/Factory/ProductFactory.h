#pragma once
#include <Interface/FactoryTemplate.h> // Use the template interface class
#include <Model/Product.h>

// concrete class implements a Product template factory
class ProductFactory: public FactoryTemplate<Product>
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

	// default destructor
	~ProductFactory() = default;
};
