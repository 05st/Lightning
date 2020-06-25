#include "lnpch.h"

#include "Window.h"

namespace Lightning {
	Window::Window(std::string title, int width, int height) {
		this->title = title;
		this->width = width;
		this->height = height;

		LN_CORE_INFO("Creating window [{0}, {1}, {2}]", title, width, height);

		if (!glfwInit()) {
			LN_CORE_FATAL("Failed to initalize GLFW");
		}

		window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(window);
		glViewport(0, 0, width, height);
	}

	void Window::SetVsync(bool value) {
		vsync = value;
		glfwSwapInterval(value ? 1 : 0);
	}

	bool Window::IsVsync() {
		return vsync;
	}
}