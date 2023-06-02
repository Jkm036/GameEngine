#include "Simple2DRenderer.h"

namespace Sparky {
	namespace Graphics {

		void Simple2DRenderer::submit(const Renderable2D* renderable) 
		{
			m_RenderQueue.push_back((StaticSprite*)renderable);
		}
		void Simple2DRenderer::flush() 
		{
			while (!m_RenderQueue.empty()){
				 const StaticSprite* sprite = m_RenderQueue.front();
				sprite->getVao()->bind();
				sprite->getIbo()->bind();

				sprite->getShader().setUniformMat4("ml_matrix", Maths::Matrix4::translation(sprite->getPosition()));
				glDrawElements(GL_TRIANGLES, sprite->getIbo()->getCount(),GL_UNSIGNED_SHORT, nullptr);

				sprite->getIbo()->unbind();
				sprite->getVao()->unbind();

				m_RenderQueue.pop_front();
			}
		}
	}
}