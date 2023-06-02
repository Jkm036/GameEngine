#include "Sprite.h"
namespace Sparky {
	namespace Graphics {
	
	
		Sprite::Sprite(float x, float y, float width, float height, const Maths::Vec4& color)
		:Renderable2D(Maths::Vec3(x, y, 0), Maths::Vec2(width, height), color)
		{}
	
	
	}
}