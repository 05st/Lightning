#pragma once

#include "Shader.h"

namespace Lightning {
	class Renderer {
	public:
		Renderer();
		~Renderer() = default;

		void Prepare();

		void AddShader(std::string name, Shader shader);
		void RemoveShader(std::string name);
		void BindShader(std::string name);
		void UnbindShader(std::string name);
	private:
		std::map<std::string, Shader> shaders;
	};
}