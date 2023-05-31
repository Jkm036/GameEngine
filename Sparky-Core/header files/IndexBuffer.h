#pragma once
#include<GL/glew.h>

namespace Sparky {namespace Graphics {
	
	class IndexBuffer {
	private:
		GLuint m_BufferID;
		GLuint m_count;
	public: 
		IndexBuffer(GLushort* data, GLsizei count);
		void bind() const;
		void unbind();
		inline GLuint getCout()const { return m_count; };
	};
	
	
}}