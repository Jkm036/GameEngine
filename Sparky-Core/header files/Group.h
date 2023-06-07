#pragma once
#include "Renderable2D.h"
#include<vector>

namespace Sparky {
	namespace Graphics {
	
		class Group : public Renderable2D {
		private:
			std::vector<Renderable2D*> m_Renderables;
			Maths::Matrix4 m_transformationMatrix;
		public:
			void add(Renderable2D* renderable);
			Group(const Maths::Matrix4& tranform);
			void submit(Renderer2D* renderer)const override;

		};
	
	
	}
}