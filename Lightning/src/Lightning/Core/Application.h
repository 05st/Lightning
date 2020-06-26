#pragma once

#include "lnpch.h"

#include "Base.h"

namespace Lightning {
	class LN_API Application {
	public:
		Application(std::string title = "Lightning Application");
		virtual ~Application();

		void Run();
		void Stop();
		static void WindowCloseCallback();
	private:
		bool running = true;
	};
	Application* CreateApplication();
}