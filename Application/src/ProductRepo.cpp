#include <Repository/ProductRepo.h>
#include <Factory/ProductFactory.h>
#include <CSVLoadWriter.h>

// Default constructor for ProductRepo - Creates with a CSV Load-Writer (With the Product Factory)
ProductRepo::ProductRepo()
	: ProductRepo { "Products.csv" } // defers construction to the overload (std::string)
{};
	
// Same as default constructor but with custom string
ProductRepo::ProductRepo(std::string str)
	: ProductRepo { new CSVLoadWriter<Product> (str, ProductFactory::GetInstance()) } // defers to constructor with the overload (ReadWriteInterface<Product>* interface)
{}

// Same as other constructors but directly takes in a custom interface
ProductRepo::ProductRepo(ReadWriteInterface<Product>* interface)
	: RepositoryInterface { interface }
{}

// Add a product - Override from RepositoryInterface 
void ProductRepo::Add(Product&& product)
{
	try
	{
		// Attempt to get - if there don't do anything else
		m_data.at(product.id);
	}
	catch (const std::out_of_range& e) // catch bad access
	{
		// Add new item if not existing
		m_data.emplace(product.id, product);
	};
};

// return the underlying data structure
std::unordered_map<int, Product>& ProductRepo::Get()
{
	return m_data;
}

// Delete the Read-Write interface
ProductRepo::~ProductRepo()
{
	m_dataSourceInterface->Write(m_data);	
}
