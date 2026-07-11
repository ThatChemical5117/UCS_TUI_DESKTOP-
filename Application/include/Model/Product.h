#pragma once

#include <string>
#include <iostream>

class Product
{
public:
	enum class Category
	{
		ENTRY,
		INTERMEDIATE,
		ADVANCED,
		ULTIMATE,
		CATEGORY_MAX
	};

	const static std::string categoryStrings [static_cast<int>(Product::Category::CATEGORY_MAX)];
	static std::string_view CategoryToString(Product::Category category);
	static Product::Category CategoryFromString(std::string str);


	Product(int, std::string, std::string, std::string, int, Category);
	Product();
	
	// Mutators
	int getId() const;		
	std::string getName() const;
	std::string getDescription() const;
	std::string getPrice() const;
	int getStockCount() const;
	Category getCategory() const;

	void setId(int id);
	void setName(std::string name);
	void setDescription(std::string description);
	void setPrice(std::string price);
	void setStockCount(int stock);
	void setCategory(Category category);

	friend bool operator==(const Product& productA, const Product& productB);
	friend std::ostream& operator<<(std::ostream& stream, const Product& product);

private:
	int m_id;
	std::string m_name;
	std::string m_description;
	std::string m_price;
	int m_stockCount;
	Category m_category;
};

// Friend print function
//std::ostream& operator<<(std::ostream& stream, const Product& product);

