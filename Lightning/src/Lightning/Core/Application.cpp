#include "lnpch.h"

#include "Application.h"

namespace Lightning {
	Application::Application(std::string name) {
		Window window = Window(name);

	}

	Application::~Application() {

	}

	void Application::Run() {
		while (true);
	}
}