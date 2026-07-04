#pragma once
#include <string>

#include <Model/Product.h>
#include <Interface/RepositoryInterface.h>

// Concrete class product repository fills in implementation and types
// for the Repository Interface and Read-Write interface
class ProductRepo: public RepositoryInterface<Product>
{
private:
public:
	// Default
	ProductRepo();
	
	// Custom file path
	ProductRepo(std::string str);

	// Custom Read-Write interface
	ProductRepo(ReadWriteInterface<Product>* interface);

	// Override provided virtual functions
	void Add(Product&& item) override final;
	std::unordered_map<int, Product>& Get() override final;

	// Destructors
	~ProductRepo();
};


