#pragma once

//#include <GLFW/glfw3.h>

namespace Lightning {
	class Window {
	public:
		Window(std::string title, int width, int height);
		~Window() = default;

		//GLFWwindow* GetNativeWindow() { return window; }

		void SetVsync(bool value);
		bool IsVsync();

		std::string GetTitle() { return title; }
		int GetWidth() { return width; }
		int GetHeight() { return height; }
	private:
		//GLFWwindow* window;

		bool vsync;

		std::string title;
		int width;
		int height;
	};
}