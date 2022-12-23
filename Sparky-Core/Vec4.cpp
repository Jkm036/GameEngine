#include"Vec4.h"
 namespace Sparky {
	 namespace Maths {

		 
		 Vec4::Vec4(const float& w, const float& x, const float& y,const float& z) {
			 this->w = w;
			 this->x = x;
			 this->y = y;
			 this->z = z;
		 }

		 Vec4& Vec4::add(const Vec4& other) {
			 this->w += other.w;
			 this->x += other.x;
			 this->y += other.y;
			 this->z += other.z;
			 return *this;
		 }
		 Vec4& Vec4::subtract(const Vec4& other) {
			 this->w -= other.w;
			 this->x -= other.x;
			 this->y -= other.y;
			 this->z -= other.z;
			 return *this;
		 }
		 Vec4& Vec4::multiply(const Vec4& other) {
			 this->w *= other.w;
			 this->x *= other.x;
			 this->y *= other.y;
			 this->z *= other.z;
			 return *this;
		 }
		 Vec4& Vec4::divide(const Vec4& other) {
			 this->w /= other.w;
			 this->x /= other.x;
			 this->y /= other.y;
			 this->z /= other.z;
			 return *this;
		 }

		 std::ostream& operator<<(std::ostream& stream, const Vec4& vector) {

			 stream << "4DVector: " <<vector.w<<" , " << vector.x << " , " << vector.y << " , " << vector.z;
			 return stream;
		 }
		 Vec4& operator+(Vec4& left, const Vec4& right) {
			 return left.add(right);
		 }
		 Vec4& operator-(Vec4& left, const Vec4& right) {
			 return left.subtract(right);
		 }
		 Vec4& operator/(Vec4& left, const Vec4& right) {
			 return left.divide(right);
		 }
		 Vec4& operator*(Vec4& left, const Vec4& right) {
			 return left.multiply(right);
		 }

		 Vec4& Vec4::operator+=(const Vec4& other) {
			 return this->add(other);
		 }
		 Vec4& Vec4::operator-=(const Vec4& other) {
			 return this->subtract(other);
		 }
		 Vec4& Vec4::operator*=(const Vec4& other) {
			 return this->multiply(other);
		 }
		 Vec4& Vec4::operator/=(const Vec4& other) {
			 return this->divide(other);
		 }
		 bool Vec4::operator==(const Vec4& other) {
			 return (this->x == other.x && this->y == other.y);
		 }
		 bool Vec4::operator!=(const Vec4 other) {
			 return !(this->x == other.x && this->y == other.y);
		 }
	 };
};