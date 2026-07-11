#pragma once

class Application
{
public:
	Application() = default;
	
	//Pure virtual functions
	virtual void Initilize() = 0;
	virtual void Start() = 0;
	virtual void Terminate() = 0;

	virtual ~Application() = default;
};
