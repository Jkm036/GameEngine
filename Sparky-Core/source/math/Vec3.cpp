#include"Vec3.h"
 namespace Sparky {
	 namespace Maths {

		 Vec3::Vec3() {
			 x = 0.0f;
			 y = 0.0f;
			 z = 0.0f;

		 }
		 Vec3::Vec3(const float& x, const float& y,const float& z) {
			 this->x = x;
			 this->y = y;
			 this->z = z;
		 }

		 Vec3& Vec3::add(const Vec3& other) {
			 this->x += other.x;
			 this->y += other.y;
			 this->z += other.z;
			 return *this;
		 }
		 Vec3& Vec3::subtract(const Vec3& other) {
			 this->x -= other.x;
			 this->y -= other.y;
			 this->z -= other.z;
			 return *this;
		 }
		 Vec3& Vec3::multiply(const Vec3& other) {
			 this->x *= other.x;
			 this->y *= other.y;
			 this->z *= other.z;
			 return *this;
		 }
		 Vec3& Vec3::divide(const Vec3& other) {
			 this->x /= other.x;
			 this->y /= other.y;
			 this->z /= other.z;
			 return *this;
		 }

		 std::ostream& operator<<(std::ostream& stream, const Vec3& vector) {

			 stream << "3DVector: " << vector.x << " , " << vector.y<<" , " << vector.z;
			 return stream;
		 }
		 Vec3& operator+(Vec3& left, const Vec3& right) {
			 return left.add(right);
		 }
		 Vec3& operator-(Vec3& left, const Vec3& right) {
			 return left.subtract(right);
		 }
		 Vec3& operator/(Vec3& left, const Vec3& right) {
			 return left.divide(right);
		 }
		 Vec3& operator*(Vec3& left, const Vec3& right) {
			 return left.multiply(right);
		 }

		 Vec3& Vec3::operator+=(const Vec3& other) {
			 return this->add(other);
		 }
		 Vec3& Vec3::operator-=(const Vec3& other) {
			 return this->subtract(other);
		 }
		 Vec3& Vec3::operator*=(const Vec3& other) {
			 return this->multiply(other);
		 }
		 Vec3& Vec3::operator/=(const Vec3& other) {
			 return this->divide(other);
		 }
		 bool Vec3::operator==(const Vec3& other) {
			 return (this->x == other.x && this->y == other.y && this->z==other.z);
		 }
		 bool Vec3::operator!=(const Vec3 other) {
			 return !(this->x == other.x && this->y == other.y&& this->z==other.z);
		 }
	 };
};