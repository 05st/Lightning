#include "lnpch.h"
#include "Application.h"

namespace Lightning {
	Application::Application(std::string title, int width, int height) {
		this->width = width;
		this->height = height;
		this->title = title;

		if (!glfwInit()) { LN_CORE_FATAL("Failed to initalize GLFW"); }

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		LN_CORE_INFO("Creating window ({0}x{1}) \"{2}\"", width, height, title);
		nativeWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (!nativeWindow) { LN_CORE_FATAL("Failed to create GLFW window"); }

		glfwMakeContextCurrent(nativeWindow);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { LN_CORE_FATAL("Failed to initalize GLAD"); }

		glViewport(0, 0, width, height);
		glfwSetWindowUserPointer(nativeWindow, this);

		SetVsync(true);

		glfwSetWindowCloseCallback(nativeWindow, [](GLFWwindow* window) {
			Application* application = (Application*)glfwGetWindowUserPointer(window);
			application->WindowCloseCallback();
		});

		glfwSetWindowSizeCallback(nativeWindow, [](GLFWwindow* window, int width, int height) {
			Application* application = (Application*)glfwGetWindowUserPointer(window);
			application->WindowResizeCallback(width, height);
		});

		renderer = new Renderer();
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (running) {
			renderer->Prepare();
			
			renderer->Draw();

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