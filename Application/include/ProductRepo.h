#pragma once
#include <string>
#include <vector>
#include <optional>
#include <utility>

#include <Product.h>
#include <RepositoryInterface.h>

class ProductRepo: public RepositoryInterface<Product>
{
private:
	static std::optional<std::pair<int, Product>> lineParser(const std::vector<std::string>& line);
	static std::string productParser(const Product& product);
public:
	// Default
	ProductRepo();
	
	// Custom file path
	ProductRepo(std::string str);

	// Customer Read-Write interface
	ProductRepo(ReadWriteInterface<Product>* interface);

	std::unordered_map<int, Product>& Get() override final;

	~ProductRepo();
};


