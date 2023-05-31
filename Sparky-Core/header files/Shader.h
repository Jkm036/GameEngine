#pragma once
#include "FileUtils.h"
#include<GL/glew.h>
namespace Sparky {
	namespace Graphics {
		
		class Shader {
			public:
				const char* m_vertexPath;
				const char* m_fragPath;
				GLuint m_ShaderID;
				
			public: 
			Shader(const char* vertexPath, const char* fragPath);
			~Shader();
			unsigned int compileShader(unsigned int, const char*&);
			bool compiled(unsigned int&);
			void enable() const;
			void disable() const; 
			GLuint load();
		};
	}
}
