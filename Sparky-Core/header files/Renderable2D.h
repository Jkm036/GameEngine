#pragma once
#include<GL/glew.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include  "Shader.h"


namespace Sparky { namespace Graphics{

	class Renderable2D {
	protected:
		Maths::Vec2 m_size;
		Maths::Vec3 m_position;
		Maths::Vec4 m_color;

		Shader& m_shader;
		VertexArray* m_vertexArray;
		IndexBuffer* m_indexBuffer;

	public:
		Renderable2D(Maths::Vec3 position, Maths::Vec2 size, Maths::Vec4 color, Shader& shader)
			: m_position(position), m_size(size), m_color(color), m_shader(shader)
		{
			m_vertexArray = new VertexArray();
			GLfloat vertices[] = {
				0,0,0,
				0,size.y,0,
				size.x,size.y, 0,
				size.x,0,0,

			};
			GLfloat colors[] = {
				color.w,color.x,color.y,color.z,
				color.w,color.x,color.y,color.z,
				color.w,color.x,color.y,color.z,
				color.w,color.x,color.y,color.z,
			};
			GLushort indices[] = {
				0,1,2,
				2,3,0,
			};
			VertexBuffer verticesBuffer(vertices, 4 * 3, 3);
			VertexBuffer colorBuffer(colors, 4 * 4, 4);
			m_vertexArray->addVertexBuffer(&verticesBuffer, 0);
			m_vertexArray->addVertexBuffer(&colorBuffer, 1);

			m_indexBuffer = new IndexBuffer(indices, 6);
		}
		~Renderable2D() {
			delete m_vertexArray;
			delete m_indexBuffer;
		}
		inline Shader getShader() const { return m_shader; }
		inline const VertexArray* getVao() const { return m_vertexArray; }
		inline const IndexBuffer* getIbo() const { return m_indexBuffer; }

		inline const Maths::Vec2 getSize()
		{
			return m_size;
		}
		inline const Maths::Vec3 getPosition() const
		{
			return m_position;
		}

		inline const Maths::Vec4 getColor() const
		{
			return m_color;
		}

	};
	


}}