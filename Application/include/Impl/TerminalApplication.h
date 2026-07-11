#pragma once

#include <Interface/Application.h>

class TerminalApplication: public Application
{
public:
	TerminalApplication();	

	void Initilize() override final;
	void Start() override final;
	void Terminate() override final;

	~TerminalApplication();
};
