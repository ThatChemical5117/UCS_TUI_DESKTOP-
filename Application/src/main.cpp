#include <iostream>
#include <vector>
#include <string>

#include <Product.h>
#include <Order.h> 
#include <CSVLoader.h>

void DisplayMenu()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "- 1) List Product - " << std::endl;
	std::cout << "- 2) List Orders - " << std::endl;
	std::cout << "- 3) Change Product values - " << std::endl;
	std::cout << "- 4) Add new Product - " << std::endl;
	std::cout << "- 5) Exit -" << std::endl;
	std::cout << "----------------------" << std::endl;
}


class Repository
{
private:
public:
protected:
};

class ProductRepo
{
private:
	static ProductRepo* m_repo;
	ProductRepo();

	std::unordered_map<int, Product> m_productHashmap;
public:
	static ProductRepo* getInstance();

	const Product& getProducts();
	void addProducts();
};

class OrderRepo
{};

void ListProducts(const std::vector<Product>& products)
{
	// Repository.get()
	for (const Product& product: products)
	{
		std::cout << product << std::endl;
	}
}

void ListOrders(const std::vector<Order>& orders)
{
	for (const Order& order: orders)
	{
		std::cout << order << std::endl;
	};
}

int main()
{
	int userInput;
	CSVLoader loader;

	std::vector<Product> products;
	std::vector<Order> orders;

	loader.load("Products.csv", [&products](std::vector<std::string>& t_line) -> void
	{
		if (t_line.size() < 6)
			return;

		products.emplace_back(std::stoi(t_line[0]), t_line[1], t_line[2],std::stod(t_line[3]), std::stoi(t_line[4]), stringToProductCatagory(t_line[5]));

	});

	loader.load("Orders.csv", [&orders](std::vector<std::string>& line) -> void
	{
		if (line.size() < 5)
			return;

		orders.emplace_back(std::stoi(line[0]), std::stoi(line[1]), std::stoi(line[2]), line[3], line[4], line[5], stringToOrderStatus(line[6]));
	});

	do
	{
		DisplayMenu();
		std::cin >> userInput;

		switch (userInput)
		{
			case 1:
				ListProducts(products);
				break;
			case 2:
				ListOrders(orders);
				break;
			case 3:
				std::cout << "Not implemented\n";
				break;
			case 4:
				std::cout << "Not implemented\n";
				break;
		}

	} while (userInput != 5);
}
