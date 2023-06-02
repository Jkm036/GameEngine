#pragma once
#include<GL/glew.h>

namespace Sparky {namespace Graphics {
	
	class IndexBuffer {
	private:
		GLuint m_BufferID;
		GLuint m_count;
	public: 
		IndexBuffer(GLushort* data, GLsizei count);
		~IndexBuffer();
		void bind() const;
		void unbind() const;
		inline GLuint getCount()const { return m_count; };
	};
	
	
}}