#include "SwordSong/Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

namespace SwordSong {
	Shader::Shader(float wr, float hr) {
		this->wr = wr;
		this->hr = hr;
	}

	Shader::~Shader() {

	}

	void Shader::Load(const char* vertexPath, const char* fragmentPath) {
		// 1. retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		
		// ensure ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			// open files
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			// read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// close file handlers
			vShaderFile.close();
			fShaderFile.close();
			// convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
		}
		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		unsigned int vertex, fragment;
		int success;
		char infoLog[512];

		// vertex Shader
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		// print compile errors if any
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		};
		
		// fragment Shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		// print compile errors if any
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		};

		// shader Program
		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);
		// print linking errors if any
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		// delete the shaders as they're linked into our program now and no longer necessary
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void Shader::Use() {
		glUseProgram(ID);
	}

	void Shader::SetBool(const std::string &name, bool value) const
	{         
	    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
	}
	void Shader::SetInt(const std::string &name, int value) const
	{ 
	    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
	}
	void Shader::SetFloat(const std::string &name, float value) const
	{ 
	    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
	}

	void Shader::SetVec4(const std::string &name, float x, float y, float z, float a) const
	{
		glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, a);
	}

	void Shader::SetVec3(const std::string &name, float x, float y, float z) const
	{
		glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
	}

	void Shader::SetVec2(const std::string &name, float x, float y) const
	{
		glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
	}

	void Shader::SetPosition(float x, float y) const
	{
		GLuint modelMatIdx = glGetUniformLocation(ID, "modelMat");
		GLuint viewMatIdx = glGetUniformLocation(ID, "viewMat");
		GLuint projMatIdx = glGetUniformLocation(ID, "projMat");

		glm::mat4 Projection = glm::mat4(1.0f);
		glm::mat4 View = glm::mat4(1.0f);
		View = glm::scale(View, glm::vec3(32/wr, 32/hr, 1.0f));
	    glm::mat4 Model = glm::mat4(1.0f);
		Model = glm::translate(Model, glm::vec3(x, y, 0));

		glUniformMatrix4fv(modelMatIdx, 1, GL_FALSE, glm::value_ptr(Model));
		glUniformMatrix4fv(viewMatIdx, 1, GL_FALSE, glm::value_ptr(View));
		glUniformMatrix4fv(projMatIdx, 1, GL_FALSE, glm::value_ptr(Projection));
	}
}