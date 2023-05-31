#include<GL/glew.h>
#include "IndexBuffer.h"
namespace Sparky {
	namespace Graphics {

		IndexBuffer::IndexBuffer(GLushort * data, GLsizei count)
		:m_count(count){
			glGenBuffers( 1, &m_BufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
		void IndexBuffer::bind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
		}
		void IndexBuffer::unbind() {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}