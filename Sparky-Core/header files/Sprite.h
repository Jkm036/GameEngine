#pragma once
#include "renderable2D.h"

namespace Sparky {namespace Graphics{
	
	class Sprite :public Renderable2D {
	public:
		Sprite(float x, float y, float width, float height, const Maths::Vec4& color);
	};
	
}}