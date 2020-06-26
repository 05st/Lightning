#include "lnpch.h"
#include "Renderer.h"

namespace Lightning {
	Renderer::Renderer() {
		std::string vertexShaderSource = R"(
			#version 460 core
			layout (location = 0) in vec3 vertexPosition;

			uniform mat4 model;
			uniform mat4 view;
			uniform mat4 projection;

			void main() {
				gl_Position = vec4(vertexPosition, 1.0f);
			}
		)";

		std::string fragmentShaderSource = R"(
			#version 460 core
			out vec4 FragColor;

			void main() {
				FragColor = vec4(1.0f, 1.0f, 1.0f, 0.0f);
			}
		)";

		Shader defaultShader = Shader(vertexShaderSource, fragmentShaderSource);
		AddShader("default", defaultShader);
		BindShader("default");
	}
	
	void Renderer::Prepare() {
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::AddShader(std::string name, Shader shader) {
		shaders[name] = shader;
	}

	void Renderer::RemoveShader(std::string name) {
		if (!(shaders.find(name) == shaders.end())) {
			if (boundedShader == name) UnbindShader(name);
			shaders.erase(name);
		}
		else {
			LN_CORE_ERROR("Shader {0} is not in map", name);
		}
	}
	
	void Renderer::BindShader(std::string name) {
		if (!(shaders.find(name) == shaders.end())) {
			if (!boundedShader.empty()) UnbindShader(boundedShader);
			shaders[name].Bind();
		}
		else {
			LN_CORE_ERROR("Shader {0} is not in map", name);
		}
	}

	void Renderer::UnbindShader(std::string name) {
		if (!(shaders.find(name) == shaders.end())) {
			if (boundedShader == name) {
				shaders[name].Unbind();
			}
		}
		else {
			LN_CORE_ERROR("Shader {0} is not in map", name);
		}
	}
}