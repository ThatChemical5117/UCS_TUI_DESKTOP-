#include <Product.h>

const static std::string productCategoryStrings [static_cast<int>(ProductCatagory::CATEGORY_MAX)] = { "entry", "intermediate","advanced", "ultimate" };

Product::Product(int t_id, std::string t_name, std::string t_description, double t_price, int t_stockCount, ProductCatagory t_category)
	: id { t_id }, name { t_name }, description { t_description }, price { t_price }, stockCount { t_stockCount }, category { t_category }
{
}

std::string_view ProductCatagoryToString(ProductCatagory cat)
{
	return productCategoryStrings[static_cast<int>(cat)];
};

ProductCatagory stringToProductCatagory(std::string_view str)
{
	for (unsigned int i = 0; i < static_cast<int>(ProductCatagory::CATEGORY_MAX); i++)
	{
		if (str.compare(productCategoryStrings[i]) == 0)
			return static_cast<ProductCatagory>(i);
	}

	return ProductCatagory::CATEGORY_MAX;
}

std::ostream& operator<<(std::ostream& stream, const Product& product)
{
	stream << product.id << "\n";
	stream << product.name << "\n\t";
	stream << product.description << "\n\t";
	stream << ProductCatagoryToString(product.category) << " level\n\t";
	stream << product.price;

	return stream;
}
