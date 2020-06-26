#include "lnpch.h"
#include "Shader.h"

#include "glad/glad.h"

namespace Lightning {
	Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath) {
		std::string vertexShaderSource = ReadFile(vertexShaderPath);
		std::string fragmentShaderSource = ReadFile(fragmentShaderPath);

		unsigned int vertexShader = CompileShader(vertexShaderSource, GL_VERTEX_SHADER);
		unsigned int fragmentShader = CompileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

		shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);

		glLinkProgram(shaderProgram);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	Shader::~Shader() {
		glDeleteProgram(shaderProgram);
	}

	unsigned int Shader::CompileShader(std::string source, unsigned int shaderType) {
		unsigned int shader = glCreateShader(shaderType);

		const char* source_cstr = source.c_str();
		glShaderSource(shader, 1, &source_cstr, NULL);
		glCompileShader(shader);

		return shader;
	}

	void Shader::Bind() {
		glUseProgram(shaderProgram);
	}

	void Shader::Unbind() {
		glUseProgram(0);
	}

	std::string Shader::ReadFile(std::string filePath) {
		std::ifstream ifs;
		ifs.open(filePath);

		std::stringstream stream;
		stream << ifs.rdbuf();
		ifs.close();

		return stream.str();
	}
}