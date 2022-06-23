#include"Vec2.h"
 namespace Sparky {
 namespace Maths {

	 Vec2::Vec2() {
		 x = 0.0f;
		 y = 0.0f;

	 }
	 Vec2::Vec2(const float& x, const float& y) {
		 this -> x = x;
		 this -> y = y;
	 }

	 Vec2& Vec2::add(const Vec2& other) {
		this-> x += other.x;
		 this->y += other.y;
		 return *this;
	 }
	 Vec2& Vec2::subtract(const Vec2& other) {
		 this->x -= other.x;
		 this->y -= other.y;
		 return *this;
	 }
	 Vec2& Vec2::multiply(const Vec2& other) {
		 this->x *= other.x;
		 this->y *= other.y;
		 return *this;
	 }
	 Vec2& Vec2::divide(const Vec2& other) {
		 this->x /= other.x;
		 this->y /= other.y;
		 return *this;
	 }

	 std::ostream& operator<<(std::ostream& stream, const Vec2& vector) {
	 
		 stream << "2DVector: " << vector.x << " , " << vector.y;
		 return stream;
	 }
	 Vec2& operator+(Vec2& left, const Vec2& right) {
		 return left.add(right);
	 }
	 Vec2& operator-(Vec2& left, const Vec2& right) {
		 return left.subtract(right);
	 }
	 Vec2& operator/(Vec2& left, const Vec2& right) {
		 return left.divide(right);
	 }
	 Vec2& operator*(Vec2& left, const Vec2& right) {
		 return left.multiply(right);
	 }

	 Vec2& Vec2::operator+=(const Vec2& other) {
	 
	 }
	 Vec2& Vec2::operator-=(const Vec2& other){
	 }
	 Vec2& Vec2::operator*=(const Vec2& other) {
	 }
	 Vec2& Vec2::operator/=(const Vec2& other) {
	 }
	}
};