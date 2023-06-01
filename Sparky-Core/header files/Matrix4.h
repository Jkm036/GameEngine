#pragma once
#include<iostream>
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h" 
namespace Sparky {
	namespace Maths {

		struct Matrix4 {
			union {
				float elements[16];
				Vec4 colums[4];
			};
			
			Matrix4();
			Matrix4(float diagonal);
			static Matrix4 identity();
			static Matrix4 orthographic(float left, float right,float bottom, float top, float near, float far);
			static Matrix4 perspective(float fov, float aspect_ration, float near, float far);
			static Matrix4 translation(const Vec3& translation);
			static Matrix4 rotation(float angle, const Vec3& axis);
			static Matrix4 scale(const Vec3& scale);

			friend std::ostream& operator<<(std::ostream&, const Matrix4&);
			friend Matrix4 operator*(Matrix4 left, const Matrix4& right);
			Matrix4& operator*=(const Matrix4& other);

			Matrix4& mupltiply(const Matrix4& other);		
		};
	
	}
}
