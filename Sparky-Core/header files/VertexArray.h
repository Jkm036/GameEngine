#pragma once
#include<Gl/glew.h>
#include "VertexBuffer.h"
#include <vector>

namespace Sparky {
	namespace Graphics {
		class VertexArray {
		private:
			GLuint m_ArrayID;
			std::vector<VertexBuffer*> m_buffers;
		public:
			VertexArray();
			~VertexArray();
			void addVertexBuffer(VertexBuffer*, GLuint index);
			void bind() const;
			void unbind()const ;
		};
	}
}