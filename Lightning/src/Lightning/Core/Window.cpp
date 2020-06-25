#include "Window.h"

#include <iostream>

namespace Lightning {
	Window::Window(std::string title, int width, int height) {
		this->title = title;
		this->width = width;
		this->height = height;
	}

	void Window::SetVsync(bool value) {
		vsync = value;
	}

	bool Window::IsVsync() {
		return vsync;
	}
}