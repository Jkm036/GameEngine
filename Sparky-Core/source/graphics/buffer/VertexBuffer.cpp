#include"VertexBuffer.h"
#include<GL/glew.h>

namespace Sparky {namespace Graphics {
	
	

		VertexBuffer::VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount)
			:m_componentCount(componentCount)
		{
			glGenBuffers(1, &m_BufferID);
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		VertexBuffer::~VertexBuffer() 
		{
			glDeleteBuffers(1, &m_BufferID);

		}
		void VertexBuffer::bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		}
		void VertexBuffer::unbind() {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	



}}