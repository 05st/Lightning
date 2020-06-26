#pragma once

namespace Lightning {
	class Shader {
	public:
		Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
		~Shader();

		void Bind();
		void Unbind();
	private:
		unsigned int shaderProgram;

		unsigned int CompileShader(std::string source, unsigned int shaderType);
		std::string ReadFile(std::string filePath);
	};
}