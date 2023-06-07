#include"Group.h"


namespace Sparky {
	namespace Graphics {
		Group::Group(const Maths::Matrix4& transform)
		:m_transformationMatrix(transform)
		{}


		void Group::submit(Renderer2D* renderer)const {
			renderer->push(m_transformationMatrix);

			for (const Renderable2D* renderable : m_Renderables) {
				renderable->submit(renderer);
			}
			renderer->pop();

		}
		void Group::add(Renderable2D* renderable) {
			m_Renderables.push_back(renderable);
		
		}


	
	}
}