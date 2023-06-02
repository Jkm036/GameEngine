#include "StaticSprite.h"

namespace Sparky {
	namespace Graphics {
	
		StaticSprite::StaticSprite(float x, float y, float width, float height, const Maths::Vec4& color, Shader &shader)
			:Renderable2D(Maths::Vec3(x,y,0), Maths::Vec2(width,height),color),m_shader(shader)
		{

			m_vertexArray = new VertexArray();
			GLfloat vertices[] = {
				0,0,0,
				0,height,0,
				width,height, 0,
				width,0,0,

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
			//all buffers are presumed to be floats
			VertexBuffer verticesBuffer(vertices, 4 * 3, 3);
			VertexBuffer colorBuffer(colors, 4 * 4, 4);
			m_vertexArray->addVertexBuffer(&verticesBuffer, 0);
			m_vertexArray->addVertexBuffer(&colorBuffer, 1);

			m_indexBuffer = new IndexBuffer(indices, 6);
		}

		StaticSprite::~StaticSprite() 
		{
			delete m_vertexArray;
			delete m_indexBuffer;
		}
	}
}