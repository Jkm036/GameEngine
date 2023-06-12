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
		Maths::Vec2 uv;
		unsigned int  color;
	};

	class Renderable2D {
	protected:
		Maths::Vec2 m_size;
		Maths::Vec3 m_position;
		Maths::Vec4 m_color;
		std::vector<Maths::Vec2> m_UVs;
	public:
		Renderable2D() {setUVDefaults();};

	public:
		Renderable2D(Maths::Vec3 position, Maths::Vec2 size, Maths::Vec4 color)
			: m_position(position), m_size(size), m_color(color)
		{setUVDefaults();}
		~Renderable2D() {}
		virtual void submit(Renderer2D* renderer) const {
			renderer->submit(this);
		}

		inline const Maths::Vec2 getSize() const
		{return m_size;}
		inline const Maths::Vec3 getPosition() const
		{return m_position;}
		inline const Maths::Vec4 getColor()const
		{return m_color;}
		inline  const std::vector<Maths::Vec2>& getUVs() const 
		{return m_UVs; }
	private:
		void setUVDefaults() {
			m_UVs.push_back(Maths::Vec2(0, 0));
			m_UVs.push_back(Maths::Vec2(0, 1));
			m_UVs.push_back(Maths::Vec2(1, 1));
			m_UVs.push_back(Maths::Vec2(1, 0));
		}

	};
	


}}