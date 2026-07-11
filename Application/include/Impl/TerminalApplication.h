#pragma once

#include <Model/Product.h>
#include <Model/Order.h>

#include <Interface/Application.h>
#include <Interface/RepositoryInterface.h>

class TerminalApplication: public Application
{
public:
	TerminalApplication();	

	void Start() override final;

	~TerminalApplication();
public:
	RepositoryInterface<Product> m_productRepo;
	RepositoryInterface<Order> m_orderRepo;
};
