#pragma once

#include "lnpch.h"

#include "GLFW/glfw3.h"
#include "Base.h"

namespace Lightning {
	class LN_API Application {
	public:
		Application(std::string title = "Lightning Application", int width = 1280, int height = 720);
		virtual ~Application();

		void SetVsync(bool enabled);

		GLFWwindow* GetNativeWindow() { return nativeWindow; }
		int GetWidth() { return width; }
		int GetHeight() { return height; }
		std::string GetTitle() { return title; }
		bool IsVsync() { return vsync; }
		bool IsRunning() { return running; }
		bool IsFullscreen() { return fullscreen; }

		void Run();
	private:
		GLFWwindow* nativeWindow;

		int width, height;
		std::string title;

		bool vsync = false;
		bool fullscreen = false;
		bool running = true;

		void WindowCloseCallback();
		void WindowResizeCallback(int width, int height);
	};
	Application* CreateApplication();
}