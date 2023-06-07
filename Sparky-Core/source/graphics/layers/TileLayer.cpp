#include "TileLayer.h"
#include "BatchRenderer2D.h"
namespace Sparky {
	namespace Graphics {
		TileLayer::TileLayer(Shader* shader)
			: Layer(new BatchRenderer2D(), shader, Maths::Matrix4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f,-1,1))
		{

		
		}

		TileLayer::~TileLayer() {
		}
	
	}
}