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
				
				GLint getUniformLocation(const GLchar* name);
			public: 
			GLuint m_ShaderID;
			Shader(const char* vertexPath, const char* fragPath);
			~Shader();

			
			void setUniform1f(const GLchar* name, float val);
			void setUniform1fv(const GLchar* name, float* val, int count);
			void setUniform1i(const GLchar* name,int val);
			void setUniform1iv(const GLchar* name, int* val, int count);

			
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
