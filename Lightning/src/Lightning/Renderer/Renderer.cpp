#include "lnpch.h"
#include "Renderer.h"

namespace Lightning {
	Renderer::Renderer() {
		std::string vertexShaderSource = "";
		std::string fragmentShaderSource = "";

		
	}
	
	void Renderer::Prepare() {
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::AddShader(std::string name, Shader shader) {

	}

	void Renderer::RemoveShader(std::string name) {

	}
	
	void Renderer::BindShader(std::string name) {

	}

	void Renderer::UnbindShader(std::string name) {

	}
}