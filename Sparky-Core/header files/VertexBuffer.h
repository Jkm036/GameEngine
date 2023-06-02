#pragma once

#include<GL/glew.h>

namespace Sparky {
	namespace Graphics {
		class VertexBuffer {
		private:
			GLuint m_BufferID;
			GLuint m_componentCount;
		public:

			VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount);
			~VertexBuffer();
			void bind() const;
			void unbind();

			inline GLuint getcomponentCount() const { return m_componentCount; };
		};
	}
}