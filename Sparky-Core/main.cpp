
#include <iostream>
#include "Window.h"
#include "Vec2.h"
int main() {
	Sparky::Maths::Vec2 v(1.0f, 2.0f);
	Sparky::Maths::Vec2 w(3.0f, 2.0f);
	Sparky::Maths::Vec2 x=v+w;
	Sparky::Graphics::Window window(800, 600, "Joshua Muthii");
	glClearColor(.2f, .3f, .8f, 1.0f);
	std::cout << x << std::endl;
	
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