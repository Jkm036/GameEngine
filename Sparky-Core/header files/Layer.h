#pragma once
#include "Renderer2D.h"
#include "Renderable2D.h"

namespace Sparky {
	namespace Graphics{
		class Layer {
		protected:
			Renderer2D* m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader* m_Shader;
			Maths::Matrix4 m_ProjectionMatrix;
		protected:
			Layer(Renderer2D* renderer,Shader* shader,  Maths::Matrix4 projectionMatrix);
			Layer();
		public:
			
			virtual ~Layer();
			virtual void add(Renderable2D* renderable);
			virtual void render();
		};
	}
}