#include "BatchRenderer2D.h"
#include "VertexArray.h"
namespace Sparky {
	namespace Graphics {

		BatchRenderer2D::BatchRenderer2D():m_IndexCount(0) {
			init();

		}
		BatchRenderer2D::~BatchRenderer2D() {
			delete m_Ibo;
			glDeleteBuffers(1, &m_Vbo);

		}
		void BatchRenderer2D::init() {
			glGenVertexArrays(1, &m_Vao);
			glBindVertexArray(m_Vao);
			glGenBuffers(1, &m_Vbo);
			glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
			glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, nullptr, GL_DYNAMIC_DRAW);
			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT,GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)0);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);																		
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)(3* sizeof(GLfloat)));
			glBindBuffer(GL_ARRAY_BUFFER,0);
			

			GLushort indices[RENDERER_INDICES_SIZE];
			int originVertex = 0;

			for (int i = 0; i < RENDERER_INDICES_SIZE ; i+=6) {
				
				indices[i + 0] = originVertex + 0;
				indices[i + 1] = originVertex + 1;
				indices[i + 2] = originVertex + 2;

				indices[i + 3] = originVertex + 2;
				indices[i + 4] = originVertex + 3;
				indices[i + 5] = originVertex + 0;

				originVertex += 4;

			}
			m_Ibo = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
			glBindVertexArray(0);
		}

		void BatchRenderer2D::submit(const Renderable2D* renderable) {
			Maths::Vec3 position = renderable->getPosition();
			Maths::Vec2 size     = renderable->getSize();
			Maths::Vec4 color    = renderable->getColor();

			m_VertexBuffer->vertex = position;
			m_VertexBuffer->color = color;
			m_VertexBuffer++;

			m_VertexBuffer->vertex = Maths::Vec3(position.x, (position.y + size.y), position.z);
			m_VertexBuffer->color = color;
			m_VertexBuffer++;

			m_VertexBuffer->vertex = Maths::Vec3((position.x+ size.x), (position.y + size.y), position.z);
			m_VertexBuffer->color = color;
			m_VertexBuffer++;

			m_VertexBuffer->vertex = Maths::Vec3((position.x + size.x), position.y , position.z);
			m_VertexBuffer->color = color;
			m_VertexBuffer++;

			m_IndexCount+=6;
		}
		void BatchRenderer2D::Begin() {
			glBindBuffer(GL_ARRAY_BUFFER,m_Vbo);
			m_VertexBuffer = (vertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}
		void BatchRenderer2D::End() {
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);

		}
		void BatchRenderer2D::flush() {
			glBindVertexArray(m_Vao);
			m_Ibo->bind();
				glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, NULL);
			m_Ibo->unbind();
			glBindVertexArray(0);
			m_IndexCount = 0;

		}
	}
}