#pragma once

#include <Model/Product.h>
#include <Model/Order.h>

#include <Interface/Application.h>
#include <Interface/RepositoryInterface.h>

class TUIApplication: public Application
{
public:
	// Constructor
	TUIApplication();

	// Start main application loop
	void Start() override final;

	// Destructor
	~TUIApplication();
private:
	RepositoryInterface<Product> m_productRepo;
	RepositoryInterface<Order> m_orderRepo;
};
