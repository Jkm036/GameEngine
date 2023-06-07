#pragma once
#define RENDERER_MAX_SPRITES   10000
#define RENDERER_VERTEX_SIZE   sizeof(vertexData)
#define RENDERER_SPRITE_SIZE   RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE   RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE   RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX  1
#include <cstddef>
#include "Renderer2D.h"
#include "Renderable2D.h"
#include "IndexBuffer.h"
namespace Sparky {
	namespace Graphics {
	


		class BatchRenderer2D: public Renderer2D {
		private:
			GLuint m_Vao;
			IndexBuffer* m_Ibo;
			vertexData* m_VertexBuffer;
			GLsizei m_IndexCount;
			GLuint m_Vbo;
		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void Begin() override ;
			void submit(const Renderable2D* renderable) override;
			void End()   override ;
			void flush() override;
		private:
			void init();
		};
	
	}
}