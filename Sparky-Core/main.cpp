
#include <iostream>
#include "Window.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Matrix4.h"
#include "FileUtils.h"
int main() {
	Sparky::Maths::Vec2 v(1.0f, 2.0f);
	Sparky::Maths::Vec2 w(3.0f, 2.0f);
	Sparky::Maths::Vec2 y(4.0, 4.0);
	Sparky::Maths::Vec2 x=v+w;
	Sparky::Maths::Vec4 a(1.0f, 2.3f, 3.0f, 4.0f);
	Sparky::Maths::Matrix4 mat(14);
	//x == y;
	//Sparky::Graphics::Window window(800, 600, "Joshua Muthii");
	//glClearColor(.8f, .3f, .8f, .5f);
	//std::cout << mat << std::endl;
	std::cout << sizeof(v) << std::endl;
	
	/*while (!window.closed()) {
		window.clear();
		window.tick();
	}*/
}
/*glBegin(GL_QUADS);
		glVertex2f(0.5f,0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(-0.5f, -0.5f);
		glEnd();*/