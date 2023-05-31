#pragma once
#include "FileUtils.h"
#include<GL/glew.h>
#include "Matrix4.h"
#include "Vec2.h"
namespace Sparky {
	namespace Graphics {
		
		class Shader {
			private:
				const char* m_vertexPath;
				const char* m_fragPath;
				GLuint m_ShaderID;
				GLint getUniformLocation(const GLchar* name);
			public: 
			Shader(const char* vertexPath, const char* fragPath);
			~Shader();

			
			void setUniform1f(const GLchar* name, float val);
			void setUniform1i(const GLchar* name,int val);
			
			void setUniform3f(const GLchar* name,  const Maths::Vec3& vector);
			void setUniform2f(const GLchar* name, const Maths::Vec2& vector);
			void setUniform4f(const GLchar* name,  const Maths::Vec4& vector);
			void setUniformMat4(const GLchar* name,const Maths::Matrix4& matrix);
			unsigned int compileShader(unsigned int, const char*&);
			bool compiled(unsigned int&);
			void enable() const;
			void disable() const; 
			GLuint load();
		};
	}
}
