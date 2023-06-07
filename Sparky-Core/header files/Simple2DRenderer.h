#pragma once
#include <deque>
#include "Renderable2D.h"
#include "StaticSprite.h"


namespace Sparky {namespace Graphics {

	class Simple2DRenderer: public Renderer2D{
	private:
		std::deque<const StaticSprite* >m_RenderQueue;

	public:
		virtual void submit(const Renderable2D* renderable) override;
		virtual void flush() override;
	
	};


}}