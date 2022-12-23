#pragma once
#include "FileUtils.h"
#include<GL/glew.h>
namespace Sparky {
	namespace Graphics {
		
		class Shader {
			private:
				const char* m_vertexPath;
				const char* m_fragPath;
				GLuint m_ShaderID;
				
			

			public: 
			Shader(const char* vertexPath, const char* fragPath);
			~Shader();

			void enable() const;
			void disable() const;
		private: 
			GLuint load();
		};
	}
}
