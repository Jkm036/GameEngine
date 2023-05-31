#include "VertexArray.h"
#include <vector>
#include <GL/glew.h>
namespace Sparky {
	namespace Graphics {
		VertexArray::VertexArray() {
			glGenVertexArrays(1, &m_ArrayID);
		}
		VertexArray::~VertexArray() {
			for (int i = 0; i < m_buffers.size(); ++i) {
				delete m_buffers[i];
			}
		}
		void VertexArray::addVertexBuffer(VertexBuffer* buffer, GLuint index) {
			bind();
			buffer->bind();
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->getcomponentCount(),GL_FLOAT,GL_FALSE,0,0);
			buffer->unbind();
			unbind();
		}
		void VertexArray::bind() const {
			glBindVertexArray(m_ArrayID);
		}
		void VertexArray::unbind()const {
			glBindVertexArray(0);
		}

	}
}