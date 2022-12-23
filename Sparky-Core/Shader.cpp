#include "shader.h"
namespace Sparky{
	namespace Graphics {
		
		Shader::Shader(const char* vertexPath, const char* fragPath)
		{
			m_ShaderID = load();
		}
		GLuint Shader::load() {
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
			
			const char* vertSource = read_file(m_vertexPath).c_str();
			const char* fragSource = read_file(m_fragPath).c_str();
			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

		}

	}
}