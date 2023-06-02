#pragma once
#include "Renderable2D.h""
namespace Sparky {namespace Graphics {
	
	class StaticSprite: public Renderable2D {
	private:
		Shader& m_shader;
		VertexArray* m_vertexArray;
		IndexBuffer* m_indexBuffer;
	public:
		StaticSprite(float x, float y, float width, float height, const Maths::Vec4& color, Shader& shader);
		~StaticSprite();
		inline Shader getShader() const { return m_shader; }
		inline const VertexArray* getVao() const { return m_vertexArray; }
		inline const IndexBuffer* getIbo() const { return m_indexBuffer; }

	};



}}