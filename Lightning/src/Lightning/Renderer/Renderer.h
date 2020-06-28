#pragma once

#include "glad/glad.h"
#include "Shader.h"
#include "Lightning/Renderer/VertexArray.h"

namespace Lightning {
	class LN_API Renderer {
	public:
		Renderer(bool defaultShaders = true);
		~Renderer() = default;

		void Prepare();
		void Draw();

		void AddShader(std::string name, Shader* shader);
		void RemoveShader(std::string name);
		void BindShader(std::string name);
		void UnbindShader(std::string name);

		void AddVertexArray(VertexArray* vertexArray);
	private:
		std::vector<VertexArray*> toDraw;
		std::map<std::string, Shader*> shaders;
		std::string boundedShader;
	};
}