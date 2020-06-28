#include "lnpch.h"

#include "Shader.h"

namespace Lightning {
	Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath) {
		std::string vertexShaderSource = ReadFile(vertexShaderPath);
		std::string fragmentShaderSource = ReadFile(fragmentShaderPath);

		shaderProgram = CreateShaderProgram(vertexShaderSource, fragmentShaderSource);
	}

	Shader::Shader(std::string vertexShaderSource, std::string fragmentShaderSource) {
		shaderProgram = CreateShaderProgram(vertexShaderSource, fragmentShaderSource);
	}

	Shader::~Shader() {
		glDeleteProgram(shaderProgram);
	}

	unsigned int Shader::CreateShaderProgram(std::string vertexShaderSource, std::string fragmentShaderSource) {
		unsigned int vertexShader = CompileShader(vertexShaderSource, GL_VERTEX_SHADER);
		unsigned int fragmentShader = CompileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

		unsigned int program = glCreateProgram();

		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);

		glLinkProgram(program);

		int success;
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetProgramInfoLog(program, 512, NULL, infoLog);

			glDeleteProgram(program);
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			LN_CORE_ERROR("Failed to link shader program {0} {1}", program, infoLog);
			return 0;
		}

		glDetachShader(program, vertexShader);
		glDetachShader(program, fragmentShader);

		return program;
	}

	unsigned int Shader::CompileShader(std::string source, unsigned int shaderType) {
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		unsigned int shader = glCreateShader(shaderType);

		const char* source_cstr = source.c_str();
		glShaderSource(shader, 1, &source_cstr, NULL);
		glCompileShader(shader);

		int success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetShaderInfoLog(shader, 512, NULL, infoLog);

			std::string shaderTypeName;
			switch (shaderType) {
			case GL_VERTEX_SHADER:
				shaderTypeName = "VertexShader";
				break;
			case GL_FRAGMENT_SHADER:
				shaderTypeName = "FragmentShader";
				break;
			}

			LN_CORE_ERROR("Failed to compile shader {0} {1}", shaderType, infoLog);
			return 0;
		}

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