#pragma once
#include "Layer.h"

namespace Sparky {
	namespace Graphics {
		class TileLayer : public Layer {
		public:
			TileLayer(Shader* shader);
			~TileLayer();
			
		};
	}
}