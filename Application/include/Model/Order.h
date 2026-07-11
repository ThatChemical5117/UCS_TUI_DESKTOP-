#pragma once
#include <string>

class Order
{
public:
	enum class Status {
		RECEIVED,
		RREPARING,
		BUILDING,
		TESTING,
		READY,
		SHIPPING,
		FULFILLED,
		STATUS_MAX
	};

	const static std::string statusStrings [static_cast<int>(Status::STATUS_MAX)];
	static std::string_view StatusToString(Status status);
	static Status StatusFromString(const std::string& str);

	Order(int id, int productId, int stockNumber, std::string name, std::string email, std::string address, Status status);
	Order();

	// Accessors
	int getId() const;
	int getProductId() const;
	int getStockNumber() const;
	std::string getName() const;
	std::string getEmail() const;
	std::string getAddress() const;
	Status getStatus() const;

	// Mutators
	void setId(int id);
	void setProductId(int productId);
	void setStockNumber(int stockNumber);
	void setName(std::string name);
	void setEmail(std::string email);
	void setAddress(std::string address);
	void setStatus(Status status);

	friend std::ostream& operator<<(std::ostream& stream, const Order& order);
	friend bool operator==(const Order& order, const Order& order2);

private:
	int m_id;
	int m_productId;
	int m_stockNumber;

	std::string m_name;
	std::string m_email;
	std::string m_address;


	Status m_status;
};



// overload << to print
