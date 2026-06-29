#include <ProductRepo.h>
#include <CSVLoadWriter.h>

std::optional<std::pair<int, Product>> ProductRepo::lineParser(const std::vector<std::string>& line)
{
	if (line.size() < 6)
		return {};

	int key = std::stoi(line.at(0));

	return { { 
		key, 
		{ key, line[1], line[2], std::stod(line[3]), std::stoi(line[4]), stringToProductCatagory(line[5]) }
	} };
};

std::string ProductRepo::productParser(const Product& product)
{
	return "";
};

ProductRepo::ProductRepo()
	: RepositoryInterface { new CSVLoadWriter<Product> ("Products.csv", lineParser, productParser) }
{};
	
ProductRepo::ProductRepo(std::string str)
	: RepositoryInterface { new CSVLoadWriter<Product> (str, lineParser, productParser) }
{}

ProductRepo::ProductRepo(ReadWriteInterface<Product>* interface)
	: RepositoryInterface { interface }
{}

std::unordered_map<int, Product>& ProductRepo::Get()
{
	return m_data;
}

ProductRepo::~ProductRepo()
{}


