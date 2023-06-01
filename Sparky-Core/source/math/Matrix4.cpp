#include "Matrix4.h"
#include<math.h>
#include "MyMath.h"
#define _USE_MATH_DEFINES
namespace Sparky {
	namespace Maths {

		Matrix4::Matrix4() {
			for (int i = 0; i < 16; i++) {
				elements[i] = 0;
			}
		}
		Matrix4::Matrix4(float diagonal) {
			for (int i = 0; i < 16; i++)
				elements[i] = 0;
			elements[0 + (0 * 4)] = diagonal;
			elements[1 + (1 * 4)] = diagonal;
			elements[2 + (2 * 4)] = diagonal;
			elements[3 + (3 * 4)] = diagonal;
		}

		Matrix4 Matrix4::identity() {
			return Matrix4::Matrix4(1);
		}

		Matrix4& Matrix4::mupltiply(const Matrix4& other) {
			for (int r = 0; r < 4;  r++) {
				for (int c = 0; c < 4; c++) {
					float sum = 0.0f;
					for( int element = 0; element < 4; element++){
						sum += this->elements[(element * 4) + r] * other.elements[(c * 4) + element];
					}
					elements[r + (c * 4)]=sum;
				}
			}
			return *this;
		}

		Matrix4 Matrix4::orthographic(float left, float right, float bottom, float top, float near, float far) {
			Matrix4 result(1.0f);
				//Down Diagonal
				result.elements[(0 * 4) + 0]= 2.0f / (right-left);
				result.elements[(1 * 4) + 1] = 2.0f / (top - bottom);
				result.elements[(2 * 4) + 2] = 2.0f / (near - far);
				//Last Column
				result.elements[(4 * 3) + 0] = (left + right) / (left - right);
				result.elements[(4 * 3) + 1] = (bottom + top) / (bottom-top);
				result.elements[(4 * 3) + 2] = (far+near) / (far-near);
			return result;
		}
		Matrix4 Matrix4::perspective(float fov, float aspect_ration, float near, float far) {
			Matrix4 result(1.0f);
			
			float q = 1.0f / (float)tan(myToRadians(0.5 * fov));
			float a = q / aspect_ration;
			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.elements[(0 * 4) + 0] = q;
			result.elements[(1 * 4) + 1] = a;
			result.elements[(2 * 4) + 2] = b;
			result.elements[(2 * 4) + 3] = -1.0f;
			result.elements[(3 * 4) + 2] = c;

			return result;
		}

		Matrix4 Matrix4::translation(const Vec3& translation) {
			Matrix4 result(1);

			result.elements[(3 * 4) + 0] = translation.x;
			result.elements[(3 * 4) + 1] = translation.y;
			result.elements[(3 * 4) + 2] = translation.z;
			return result;
		}

		 Matrix4 Matrix4::scale(const Vec3& scale) {
			 Matrix4 result(1.0f);
			 result.elements[(0 * 4) + 0] = scale.x;
			 result.elements[(1 * 4) + 1] = scale.y;
			 result.elements[(2 * 4) + 2] = scale.z;
			 return result;
		 }
		 Matrix4 Matrix4::rotation(float angle, const Vec3& axis){
			 Matrix4 result(1);

			 float r = myToRadians(angle);
			 float c = cos(r);
			 float s = sin(r);
			 float omc = 1.0f - c;

			 float x = axis.x;
			 float y = axis.y;
			 float z = axis.z;

			 result.elements[(0 * 4) + 0] =	(x * omc) +	c;
			 result.elements[(0 * 4) + 1] = (y * x * omc) + (z*s);
			 result.elements[(0 * 4) + 2] = (x * z * omc) - (y*s);

			 result.elements[(1 * 4) + 0] = (x * y * omc) - (z * s);
			 result.elements[(1 * 4) + 1] = ( y * omc) +(c);
			 result.elements[(1 * 4) + 2] = (y * z * omc) + (x * s);

			 result.elements[(2 * 4) + 0] = (x * z * omc) + (y * s);
			 result.elements[(2 * 4) + 1] = (y *z * omc) - (x * s);
			 result.elements[(2 * 4) + 2] = (z * omc) + (c);

			 
			 return result;
		 }

		Matrix4 operator*(Matrix4 left, const Matrix4& right) {
			return left.mupltiply(right);
		}

		Matrix4& Matrix4::operator*=(const Matrix4& other) {
			return this->mupltiply(other);
		}

		std::ostream& operator<<(std::ostream& stream, const Matrix4& mat) {
			stream << "4x4 Matrix: ";
			for (int i = 0; i < 4; i++) {
				stream << std::endl;
				for (int j = 0; j < 4; j++) {
					stream << mat.elements[i * 4 + j];
				}
				
			}
			return stream;
		}

		
	}
}