#include "shader.h"
#include<vector>
#include<iostream>
namespace Sparky{
	namespace Graphics {
		
		Shader::Shader(const char* vertexPath, const char* fragPath) :
			m_vertexPath(vertexPath), m_fragPath(fragPath)
		{
			m_ShaderID = load();
		}

		unsigned int Shader::compileShader(unsigned int type, const char*& path)
		{
			unsigned int shader = glCreateShader(type);
			//NULL means the string will be null terminated and we don't need to specify a size
			//count refers to how many source codes we are providing
			glShaderSource(shader, 1, &path, NULL);
			glCompileShader(shader);
			return shader;

		}
		GLint Shader::getUniformLocation(const GLchar* name) {
			return glGetUniformLocation(m_ShaderID, name);
		}
		void Shader::setUniform1f(const GLchar* name, float val) {
			glUniform1f(getUniformLocation(name), val);
		}
		void Shader::setUniform1fv(const GLchar* name,  float* val, int count) {
			glUniform1fv(getUniformLocation(name),count,  val);
		}
		void Shader::setUniform1i(const GLchar* name, int val) {
			glUniform1i(getUniformLocation(name), val);
		}
		void Shader::setUniform1iv(const GLchar* name, int*  val, int count) {
			glUniform1iv(getUniformLocation(name), count , val);
		}
		void Shader::setUniform2f(const GLchar* name, const Maths::Vec2& vector) {
			glUniform2f(getUniformLocation(name), vector.x, vector.y);
		}
		void Shader::setUniform3f(const GLchar* name, const Maths::Vec3& vector) {
			glUniform3f(getUniformLocation(name), vector.x,vector.y,vector.z);
		}
		void Shader::setUniform4f(const GLchar* name, const Maths::Vec4& vector) {
			glUniform4f(getUniformLocation(name), vector.w, vector.x, vector.y, vector.z);
		}
		
		void Shader::setUniformMat4(const GLchar* name, const Maths::Matrix4& matrix) {
			glUniformMatrix4fv(glGetUniformLocation(m_ShaderID, name), 1, GL_FALSE, matrix.elements);
		}
		
		
		
		bool Shader::compiled(unsigned int& shader){
			 int result;
			 int infoLogLength;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				//Getshaderiv returns info about shaders
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
				std::vector<char> error(infoLogLength);
				glGetShaderInfoLog(shader, infoLogLength, &infoLogLength, &error[0]);
				std::cout << "Shader Not Compiled: " << std::endl << &error[0] << std::endl;
				glDeleteShader(shader);
				return false;
			}
			return true;
		}
		GLuint Shader::load() {
			//Creates program binded to be binded
			GLuint program = glCreateProgram();
			//Getting source code of shaders from files
			std::string vertSourceString = FileUtils::read_file(m_vertexPath);
			std::string fragSourceString = FileUtils::read_file(m_fragPath);
			const char* vertSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();

			//these return the shader object files that need to be linked
			GLuint vertex = compileShader(GL_VERTEX_SHADER,vertSource);
			GLuint fragment = compileShader(GL_FRAGMENT_SHADER,fragSource);

			//Error Hanndling
			if (!compiled(vertex)) {
				std::cout << "In Vertex Shader: " << std::endl;
				return 0;
			}
			if (!compiled(fragment)) {
				std::cout << "In Fragment Shader: " << std::endl;
				return 0;
			}
			//attach shaders to the program
			glAttachShader(program, vertex);
			glAttachShader(program, fragment);
			//link and validate shaders
			glLinkProgram(program);
			glValidateProgram(program);
			//delete shader object files
			glDeleteShader(vertex);
			glDeleteShader(fragment);
			return program;
		}

		void Shader::enable() const {
			glUseProgram(m_ShaderID);
		}
		void Shader::disable() const {
			glUseProgram(0);
		}
		Shader::~Shader() {
			glDeleteProgram(m_ShaderID);
		}
	}
}
/*glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout <<"Failed to compile Vertex Shader!: " << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;

			}

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout <<"Failed to compile Fargment Shader!: "<< &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;

			}*/