#pragma once

#include "Base.h"

#include <string>

namespace Lightning {
	class LN_API Application {
	public:
		Application(std::string title = "Lightning Application");
		virtual ~Application();

		void Run();
	};
	Application* CreateApplication();
}