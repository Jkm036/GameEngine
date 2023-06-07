#pragma once
#include <GL/glew.h>
#include "MyMath.h"
#include <vector>


namespace Sparky {namespace Graphics {
	class Renderable2D;
	class Renderer2D {
	protected:
		std::vector<Maths::Matrix4> m_TransformationStack;
		Maths::Matrix4* m_TransformationBack;

	protected:
		Renderer2D() {
			m_TransformationStack.push_back(Maths::Matrix4::identity());
			m_TransformationBack = & m_TransformationStack.back();
		}
	public:
		void push(const Maths::Matrix4& mat, bool override = false) {
			if(override)
				m_TransformationStack.push_back(mat);
			else
				m_TransformationStack.push_back(m_TransformationStack.back() * mat);
			m_TransformationBack = &m_TransformationStack.back();

		}
		void pop() {
			if(m_TransformationStack.size()>1)
				m_TransformationStack.pop_back();

			m_TransformationBack = &m_TransformationStack.back();
		}
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void Begin() {}
		virtual void End() {}

		virtual void flush() = 0;
	};

}}