#pragma once
#include<iostream>
namespace Sparky{
	namespace Maths{
	
		struct Vec4 {
			float w,x,y,z;

			Vec4();
			Vec4(const float& w,const float& x, const float& y, const float& z);

			Vec4& add(const Vec4& other);
			Vec4& subtract(const Vec4& other );
			Vec4& multiply(const Vec4& other);
			Vec4& divide(const Vec4& other);

			//Making a way to print Vec4 has a string
			//operator overloading
			friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);
			friend Vec4& operator+(Vec4& left, const Vec4& right);
			friend Vec4& operator-(Vec4& left, const Vec4& right);
			friend Vec4& operator*(Vec4& left, const Vec4& right);
			friend Vec4& operator/(Vec4& left, const Vec4& right);

			bool operator!=(const Vec4 other);
			bool  operator==(const Vec4& other);
			Vec4& operator+=(const Vec4& other);
			Vec4& operator-=(const Vec4& other);
			Vec4& operator*=(const Vec4& other);
			Vec4& operator/=(const Vec4& other);
		};
	}
}
