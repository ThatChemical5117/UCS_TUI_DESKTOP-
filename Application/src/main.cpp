#include <Impl/TerminalApplication.h>

// Main
int main()
{
	// Create new Application
	Application* application = new TerminalApplication();

	// Start program
	application->Start();

	// Delete after
	delete application;
}

