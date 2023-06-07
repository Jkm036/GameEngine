#pragma once
#include<GL/glew.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "Renderer2D.h"
#include "MyMath.h"

namespace Sparky { namespace Graphics{
	struct vertexData {
		Maths::Vec3 vertex;
		//Maths::Vec4 color;
		unsigned int  color;
	};

	class Renderable2D {
	protected:
		Maths::Vec2 m_size;
		Maths::Vec3 m_position;
		Maths::Vec4 m_color;
	public:
		Renderable2D() {};

	public:
		Renderable2D(Maths::Vec3 position, Maths::Vec2 size, Maths::Vec4 color)
			: m_position(position), m_size(size), m_color(color)
		{
			
		}
		~Renderable2D() {}

		virtual void submit(Renderer2D* renderer) const {
			renderer->submit(this);
		}

		inline const Maths::Vec2 getSize() const
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