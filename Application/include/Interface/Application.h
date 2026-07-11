#pragma once

class Application
{
public:
	Application() = default;
	
	virtual void Start() = 0;

	virtual ~Application() = default;
};
