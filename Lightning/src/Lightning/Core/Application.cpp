#include "lnpch.h"
#include "Application.h"

namespace Lightning {
	Application::Application(std::string title, int width, int height) {
		this->width = width;
		this->height = height;
		this->title = title;

		if (!glfwInit()) { LN_CORE_FATAL("Failed to initalize GLFW"); }

		LN_CORE_INFO("Creating window ({0}x{1}) \"{2}\"", width, height, title);
		nativeWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (!nativeWindow) { LN_CORE_FATAL("Failed to create GLFW window"); }

		glfwMakeContextCurrent(nativeWindow);
		glfwSetWindowUserPointer(nativeWindow, this);
		glViewport(0, 0, width, height);

		SetVsync(true);

		glfwSetWindowCloseCallback(nativeWindow, [](GLFWwindow* window) {
			Application* application = (Application*)glfwGetWindowUserPointer(window);
			application->WindowCloseCallback();
		});

		glfwSetWindowSizeCallback(nativeWindow, [](GLFWwindow* window, int width, int height) {
			Application* application = (Application*)glfwGetWindowUserPointer(window);
			application->WindowResizeCallback(width, height);
		});

		renderer = Renderer();
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (running) {
			renderer.Prepare();

			glfwPollEvents();
			glfwSwapBuffers(nativeWindow);
		}
	}

	void Application::WindowCloseCallback() {
		running = false;
	}

	void Application::WindowResizeCallback(int width, int height) {
		glViewport(0, 0, width, height);
	}

	void Application::SetVsync(bool enabled) {
		vsync = enabled;
		glfwSwapInterval(enabled ? 1 : 0);
	}
}