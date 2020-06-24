#pragma once

#include "Core.h"

namespace Lightning {
	class LN_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	Application* CreateApplication();
}