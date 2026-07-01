#include <ProductRepo.h>
#include <CSVLoadWriter.h>
#include <sstream>

std::optional<std::pair<int, Product>> ProductRepo::lineParser(const std::vector<std::string>& line)
{
	if (line.size() < 6)
		return {};

	int key = std::stoi(line.at(0));

	return { { 
		key, 
		{ key, line[1], line[2], line[3], std::stoi(line[4]), stringToProductCatagory(line[5]) }
	} };
};

std::string ProductRepo::productParser(const Product& product)
{
	std::stringstream stream;
	stream << product.id << "," << product.name << "," << product.description << "," << product.price << "," << product.stockCount << "," << ProductCatagoryToString(product.category);

	return stream.str();
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

void ProductRepo::Add(Product&& product)
{
	try
	{
		m_data.at(product.id);
	}
	catch (const std::out_of_range& e)
	{
		m_data.emplace(product.id, product);
	};
};

std::unordered_map<int, Product>& ProductRepo::Get()
{
	return m_data;
}

ProductRepo::~ProductRepo()
{
	m_dataSourceInterface->Write(m_data);	
}


