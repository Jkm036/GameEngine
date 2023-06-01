#pragma once
#include<GL/glew.h>
#include "Renderable2D.h"

namespace Sparky {namespace Graphics {
	class Renderer2D {

	public:
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void flush() = 0;
	};

}}