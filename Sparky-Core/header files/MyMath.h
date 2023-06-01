#pragma once
#include "Matrix4.h"
#define M_PI           3.14159265358979323846

namespace Sparky {
	namespace Maths {
		float myToRadians(float degrees) {
			return degrees * ((float)M_PI / 180.0f);
		}
	}
}