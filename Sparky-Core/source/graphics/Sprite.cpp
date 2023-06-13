#include "Sprite.h"
namespace Sparky {
	namespace Graphics {
	
	
		Sprite::Sprite(float x, float y, float width, float height, const Maths::Vec4& color)
		:Renderable2D(Maths::Vec3(x, y, 0), Maths::Vec2(width, height), color)
		{}

		Sprite::Sprite(float x, float y, float width, float height, Texture* tex)
			:Renderable2D(Maths::Vec3(x, y, 0), Maths::Vec2(width, height), Maths::Vec4(1, 0, 1, 1))
		{
			m_texture=tex;
		}
	
	
	}
}